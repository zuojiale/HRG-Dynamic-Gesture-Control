#ifndef HELPER_H
#define HELPER_H

#include <array>
#include <memory>
#include <cstdint>
#include <string.h>

const int PHASE_HEIGHT = 240;
const int PHASE_WIDTH = 304;

const int IMAGE_HEIGHT = 240;
const int IMAGE_WIDTH = 288;

static const uint32_t OUTPUT_BUFFER_SIZE = PHASE_HEIGHT * PHASE_WIDTH * sizeof(int16_t);
// Helper struct for grouping outgoing data together
struct PhaseOutput
{
    std::shared_ptr<int16_t> phase1;  // has to be pre-allocated!
    std::shared_ptr<int16_t> phase2;  // has to be pre-allocated!
    std::shared_ptr<int16_t> phase3;  // has to be pre-allocated!
    std::shared_ptr<int16_t> phase4;  // has to be pre-allocated!

    /**
     * Constructor.
     * Pre-allocates the depth and confidence buffers.
     */
    PhaseOutput();
};

struct Phase8Output
{
    std::shared_ptr<int16_t> phase1;  // has to be pre-allocated!
    std::shared_ptr<int16_t> phase2;  // has to be pre-allocated!
    std::shared_ptr<int16_t> phase3;  // has to be pre-allocated!
    std::shared_ptr<int16_t> phase4;  // has to be pre-allocated!
    std::shared_ptr<int16_t> phase5;  // has to be pre-allocated!
    std::shared_ptr<int16_t> phase6;  // has to be pre-allocated!
    std::shared_ptr<int16_t> phase7;  // has to be pre-allocated!
    std::shared_ptr<int16_t> phase8;  // has to be pre-allocated!
    /**
     * Constructor.
     * Pre-allocates the depth and confidence buffers.
     */
    Phase8Output();
};

// Helper struct for grouping outgoing data together
struct AlgorithmOutput_I16
{
    std::shared_ptr<int16_t> depth;       // has to be pre-allocated!
    std::shared_ptr<int16_t> amplitude;  // has to be pre-allocated!

    /**
     * Constructor.
     * Pre-allocates the depth and confidence buffers.
     */
    AlgorithmOutput_I16();
};

// Helper struct for grouping outgoing data together
struct AlgorithmOutput_F32
{
    std::shared_ptr<float> depth;       // has to be pre-allocated!
    std::shared_ptr<int16_t> amplitude;  // has to be pre-allocated!

    /**
     * Constructor.
     * Pre-allocates the depth and confidence buffers.
     */
    AlgorithmOutput_F32();
};

/**
 * Helper template for deleting an array managed by a shared_ptr.
 */
template <typename T>
struct array_deleter
{
    void operator()(const T* ptr)
    {
        delete [] ptr;
    }
};

AlgorithmOutput_I16::AlgorithmOutput_I16()
    : depth(new int16_t[IMAGE_HEIGHT * IMAGE_WIDTH], array_deleter<int16_t>())
    , amplitude(new int16_t[IMAGE_HEIGHT * IMAGE_WIDTH], array_deleter<int16_t>())
{
    memset(depth.get(), 0, IMAGE_HEIGHT * IMAGE_WIDTH * sizeof(int16_t));
    memset(amplitude.get(), 0, IMAGE_HEIGHT * IMAGE_WIDTH * sizeof(int16_t));
}

AlgorithmOutput_F32::AlgorithmOutput_F32()
    : depth(new float[IMAGE_HEIGHT * IMAGE_WIDTH], array_deleter<float>())
    , amplitude(new int16_t[IMAGE_HEIGHT * IMAGE_WIDTH], array_deleter<int16_t>())
{
    memset(depth.get(), 0, IMAGE_HEIGHT * IMAGE_WIDTH * sizeof(float));
    memset(amplitude.get(), 0, IMAGE_HEIGHT * IMAGE_WIDTH * sizeof(int16_t));
}

PhaseOutput::PhaseOutput()
    : phase1(new int16_t[PHASE_HEIGHT * PHASE_WIDTH], array_deleter<int16_t>())
    , phase2(new int16_t[PHASE_HEIGHT * PHASE_WIDTH], array_deleter<int16_t>())
    , phase3(new int16_t[PHASE_HEIGHT * PHASE_WIDTH], array_deleter<int16_t>())
    , phase4(new int16_t[PHASE_HEIGHT * PHASE_WIDTH], array_deleter<int16_t>())
{
    memset(phase1.get(), 0, OUTPUT_BUFFER_SIZE);
    memset(phase2.get(), 0, OUTPUT_BUFFER_SIZE);
    memset(phase3.get(), 0, OUTPUT_BUFFER_SIZE);
    memset(phase4.get(), 0, OUTPUT_BUFFER_SIZE);
}

Phase8Output::Phase8Output()
    : phase1(new int16_t[PHASE_HEIGHT * PHASE_WIDTH], array_deleter<int16_t>())
    , phase2(new int16_t[PHASE_HEIGHT * PHASE_WIDTH], array_deleter<int16_t>())
    , phase3(new int16_t[PHASE_HEIGHT * PHASE_WIDTH], array_deleter<int16_t>())
    , phase4(new int16_t[PHASE_HEIGHT * PHASE_WIDTH], array_deleter<int16_t>())
    , phase5(new int16_t[PHASE_HEIGHT * PHASE_WIDTH], array_deleter<int16_t>())
    , phase6(new int16_t[PHASE_HEIGHT * PHASE_WIDTH], array_deleter<int16_t>())
    , phase7(new int16_t[PHASE_HEIGHT * PHASE_WIDTH], array_deleter<int16_t>())
    , phase8(new int16_t[PHASE_HEIGHT * PHASE_WIDTH], array_deleter<int16_t>())
{
    memset(phase1.get(), 0, OUTPUT_BUFFER_SIZE);
    memset(phase2.get(), 0, OUTPUT_BUFFER_SIZE);
    memset(phase3.get(), 0, OUTPUT_BUFFER_SIZE);
    memset(phase4.get(), 0, OUTPUT_BUFFER_SIZE);
    memset(phase5.get(), 0, OUTPUT_BUFFER_SIZE);
    memset(phase6.get(), 0, OUTPUT_BUFFER_SIZE);
    memset(phase7.get(), 0, OUTPUT_BUFFER_SIZE);
    memset(phase8.get(), 0, OUTPUT_BUFFER_SIZE);
}
#endif // HELPER_H
