#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QMovie>

#include "mp3.h"
#include "ui_mp3.h"

Mp3::Mp3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mp3)
{
    ui->setupUi(this);
    this->currentSongIndex = 0;
    this->setWindowTitle("HRG音乐播放器");
    voi = new QMediaPlayer();
    this->isPlay = false; //初始化，未播放状态
    ui->volumeSlider->setValue(0);
    ui->stopButton->setEnabled(false);
    showAllSongs();
    stopMusicLogo();
}

Mp3::~Mp3()
{
    delete ui;
}

//有音乐播放时显示动图
void Mp3::playingMusicLogo()
{
    QMovie *movie = new QMovie("../resource/有音乐.gif");
   movie->start();
    ui->iconLabel->setMovie(movie);
    ui->iconLabel->setScaledContents(true);
}

//没有音乐播放时，显示HRG
void Mp3::stopMusicLogo()
{
    QImage *logo = new QImage;
    logo->load("../resource/HRG.png");
    ui->iconLabel->setPixmap(QPixmap::fromImage(*logo));
    ui->iconLabel->setScaledContents(true);
    ui->iconLabel->show();
}

void Mp3::on_playButton_clicked()
{
    //播放
    voi->setMedia(QUrl::fromLocalFile(this->songsPath[currentSongIndex]));
    ui->songsList->setCurrentRow(this->currentSongIndex);
    voi->play();
    ui->stopButton->setEnabled(true);
    ui->volumeSlider->setValue(this->volume);
    voi->setVolume(this->volume);
    this->isPlay = !this->isPlay;
    qDebug() << this->isPlay;
    this->ui->playButton->setText(tr("Pause"));
    playingMusicLogo();
}

//一个按键实现停止操作
void Mp3::on_stopButton_clicked()
{
    //如果没有在播放
    if(this->isPlay)
    {
        voi->stop();
        qDebug("voi stop");
        this->ui->playButton->setText(tr("Play"));
        this->isPlay = !this->isPlay;
        ui->volumeSlider->setValue(0);
        ui->stopButton->setEnabled(false);
        stopMusicLogo();
    }
}


void Mp3::showAllSongs()
{
    QString root = "../song";//文件存在的目录
    QDir rootDir(root);
    QString name = "*.mp3"; //选择要筛选的文件类型
    QStringList filters; //筛选器
    filters<<name;
    QFileInfoList list = rootDir.entryInfoList(filters);

    for(unsigned int i=0; i<list.count() ;i++)
    {
        QFileInfo tmpFileInfo = list.at(i);
        if(tmpFileInfo.isDir())
        {
            QString fileName = tmpFileInfo.fileName();
            QListWidgetItem *tmp = new QListWidgetItem(fileName);
            ui->songsList->addItem(tmp);
        }
        else if(tmpFileInfo.isFile())
        {
            QString fileName = tmpFileInfo.fileName();
            QListWidgetItem *tmp = new QListWidgetItem(fileName);
            ui->songsList->addItem(tmp);
            QString path = tmpFileInfo.absolutePath() + '/' +fileName;
            this->songsPath.push_back(path);
        }
    }

}


void Mp3::volumeUp()
{
    //音量改变
    this->volume += 10;
    if(this->volume >= 100) this->volume = 100;
    voi->setVolume(this->volume);
    ui->volumeSlider->setValue(this->volume);
}

void Mp3::volumeDown()
{
    //音量改变
    this->volume -= 10;
    if(this->volume <= 0) this->volume = 0;
    voi->setVolume(this->volume);
    ui->volumeSlider->setValue(this->volume);
}

void Mp3::nextSong()
{
    //下一首
    //先停止
    voi->stop();
    this->isPlay = false;
    //再换下一首
    currentSongIndex += 1;
    if(currentSongIndex > this->songsPath.size()-1) currentSongIndex=0;//到第一首
    voi->setMedia(QUrl::fromLocalFile(this->songsPath[currentSongIndex]));
    voi->play();
    voi->setVolume(this->volume);
    ui->songsList->setCurrentRow(this->currentSongIndex);
    this->isPlay = true;
    this->ui->playButton->setText(tr("Pause"));
}



void Mp3::lastSong()
{
    //上一首
    //先停止
    voi->stop();
    this->isPlay = false;
    //再换下一首
    currentSongIndex -= 1;
    if(currentSongIndex < 0 ) currentSongIndex=songsPath.size()-1;//到最后一首
    voi->setMedia(QUrl::fromLocalFile(this->songsPath[currentSongIndex]));
    voi->play();
    voi->setVolume(this->volume);
    ui->songsList->setCurrentRow(this->currentSongIndex);
    this->isPlay = true;
    this->ui->playButton->setText(tr("Pause"));
}
