#ifndef OPENPOSE_NET_RESIZE_AND_MERGE_BASE_HPP
#define OPENPOSE_NET_RESIZE_AND_MERGE_BASE_HPP

#include <openpose/core/common.hpp>

namespace op
{
    template <typename T>
    void resizeAndMergeCpu(
        T* targetPtr, const std::vector<const T*>& sourcePtrs, const std::array<int, 4>& targetSize,
        const std::vector<std::array<int, 4>>& sourceSizes, const std::vector<T>& scaleInputToNetInputs = {1.f});

    // Windows: Cuda functions do not include OP_API
    template <typename T>
    void resizeAndMergeGpu(
        T* targetPtr, const std::vector<const T*>& sourcePtrs, const std::array<int, 4>& targetSize,
        const std::vector<std::array<int, 4>>& sourceSizes, const std::vector<T>& scaleInputToNetInputs = {1.f});

    // Windows: OpenCL functions do not include OP_API
    template <typename T>
    void resizeAndMergeOcl(
        T* targetPtr, const std::vector<const T*>& sourcePtrs, std::vector<T*>& sourceTempPtrs,
        const std::array<int, 4>& targetSize, const std::vector<std::array<int, 4>>& sourceSizes,
        const std::vector<T>& scaleInputToNetInputs = {1.f}, const int gpuID = 0);

    // Functions for cvMatToOpInput/cvMatToOpOutput
    template <typename T>
    void reorderAndCast(
        T* targetPtr, const unsigned char* const srcPtr, const int width, const int height, const int channels);

    template <typename T>
    void resizeAndMergeRGBGPU(
        T* targetPtr, const T* const srcPtr, const int sourceWidth, const int sourceHeight,
        const int targetWidth, const int targetHeight, const T scaleFactor);

    template <typename T>
    void resizeAndMergeRGBGPU(
        T* targetPtr, const unsigned char* const srcPtr, const int sourceWidth, const int sourceHeight,
        const int targetWidth, const int targetHeight, const T scaleFactor);
}
#endif // OPENPOSE_NET_RESIZE_AND_MERGE_BASE_HPP
