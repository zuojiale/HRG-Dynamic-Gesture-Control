#ifndef MP3_H
#define MP3_H

#include <QDialog>
#include <QSoundEffect>
#include <QMediaPlayer>


namespace Ui {
class Mp3;
}

class Mp3 : public QDialog
{
    Q_OBJECT

public:
    explicit Mp3(QWidget *parent = 0);
    ~Mp3();
    void playingMusicLogo();
    void stopMusicLogo();
    void showAllSongs();
    //增加音量
    void volumeUp();
    //减小音量
    void volumeDown();
    //下一首
    void nextSong();
    //上一首
    void lastSong();
public slots:
    void on_playButton_clicked();
    void on_stopButton_clicked();

private:
    Ui::Mp3 *ui;
    QMediaPlayer *voi;
    bool isPlay;  //是否在播放
    int volume = 50; //音量
    int currentSongIndex; //当前播放歌曲的编号，顺序
    std::vector<QString> songsPath;//音乐列表
};

#endif // MP3_H
