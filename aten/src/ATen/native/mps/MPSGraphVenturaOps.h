#pragma once
#include <MetalPerformanceShadersGraph/MetalPerformanceShadersGraph.h>

// TODO: Remove me when moved to MacOS 13
#if !defined(__MAC_13_0) && \
    (!defined(MAC_OS_X_VERSION_13_0) || (MAC_OS_X_VERSION_MIN_REQUIRED < MAC_OS_X_VERSION_13_0))
typedef NS_ENUM(NSUInteger, MPSGraphTensorNamedDataLayout)
{
    MPSGraphTensorNamedDataLayoutNCHW       MPS_ENUM_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0)) MPS_SWIFT_NAME(NCHW)   =  0L,
    MPSGraphTensorNamedDataLayoutNHWC       MPS_ENUM_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))                        =  1L,
    MPSGraphTensorNamedDataLayoutOIHW       MPS_ENUM_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))                        =  2L,
    MPSGraphTensorNamedDataLayoutHWIO       MPS_ENUM_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))                        =  3L,
    MPSGraphTensorNamedDataLayoutCHW        MPS_ENUM_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))                        =  4L,
    MPSGraphTensorNamedDataLayoutHWC        MPS_ENUM_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))                        =  5L,
    MPSGraphTensorNamedDataLayoutHW         MPS_ENUM_AVAILABLE_STARTING(macos(11.0), ios(14.0), tvos(14.0))                        =  6L,
    MPSGraphTensorNamedDataLayoutNCDHW      MPS_ENUM_AVAILABLE_STARTING(macos(13.2), ios(16.3), tvos(16.3))                        =  7L,
    MPSGraphTensorNamedDataLayoutNDHWC      MPS_ENUM_AVAILABLE_STARTING(macos(13.2), ios(16.3), tvos(16.3))                        =  8L,
    MPSGraphTensorNamedDataLayoutOIDHW      MPS_ENUM_AVAILABLE_STARTING(macos(13.2), ios(16.3), tvos(16.3))                        =  9L,
    MPSGraphTensorNamedDataLayoutDHWIO      MPS_ENUM_AVAILABLE_STARTING(macos(13.2), ios(16.3), tvos(16.3))                        =  10L,
};

@interface MPSGraphConvolution3DOpDescriptor : NSObject<NSCopying>

@property (readwrite, nonatomic) NSUInteger strideInX;
@property (readwrite, nonatomic) NSUInteger strideInY;
@property (readwrite, nonatomic) NSUInteger strideInZ;
@property (readwrite, nonatomic) NSUInteger dilationRateInX;
@property (readwrite, nonatomic) NSUInteger dilationRateInY;
@property (readwrite, nonatomic) NSUInteger dilationRateInZ;

@property (readwrite, nonatomic) NSUInteger paddingLeft;
@property (readwrite, nonatomic) NSUInteger paddingRight;
@property (readwrite, nonatomic) NSUInteger paddingTop;
@property (readwrite, nonatomic) NSUInteger paddingBottom;
@property (readwrite, nonatomic) NSUInteger paddingFront;
@property (readwrite, nonatomic) NSUInteger paddingBack;

@property (readwrite, nonatomic) MPSGraphPaddingStyle paddingStyle;
@property (readwrite, nonatomic) MPSGraphTensorNamedDataLayout dataLayout;
@property (readwrite, nonatomic) MPSGraphTensorNamedDataLayout weightsLayout;

/*! @property   groups
 *  @discussion groups of the operation
 */
@property (readwrite, nonatomic) NSUInteger groups;
+(nullable instancetype) descriptorWithStrideInX:(NSUInteger) strideInX
                                       strideInY:(NSUInteger) strideInY
                                       strideInZ:(NSUInteger) strideInZ
                                 dilationRateInX:(NSUInteger) dilationRateInX
                                 dilationRateInY:(NSUInteger) dilationRateInY
                                 dilationRateInZ:(NSUInteger) dilationRateInZ
                                          groups:(NSUInteger) groups
                                     paddingLeft:(NSUInteger) paddingLeft
                                    paddingRight:(NSUInteger) paddingRight
                                      paddingTop:(NSUInteger) paddingTop
                                   paddingBottom:(NSUInteger) paddingBottom
                                    paddingFront:(NSUInteger) paddingFront
                                     paddingBack:(NSUInteger) paddingBack
                                    paddingStyle:(MPSGraphPaddingStyle) paddingStyle
                                      dataLayout:(MPSGraphTensorNamedDataLayout) dataLayout
                                   weightsLayout:(MPSGraphTensorNamedDataLayout) weightsLayout;
@end
#endif


@interface MPSGraph (VenturaOps)

#if !defined(__MAC_13_0) && \
    (!defined(MAC_OS_X_VERSION_13_0) || (MAC_OS_X_VERSION_MIN_REQUIRED < MAC_OS_X_VERSION_13_0))

typedef NS_ENUM(NSUInteger, MPSGraphResizeNearestRoundingMode)
{
    MPSGraphResizeNearestRoundingModeRoundPreferCeil   =  0L,
    MPSGraphResizeNearestRoundingModeRoundPreferFloor  =  1L,
    MPSGraphResizeNearestRoundingModeCeil              =  2L,
    MPSGraphResizeNearestRoundingModeFloor             =  3L,
    MPSGraphResizeNearestRoundingModeRoundToEven       =  4L,
    MPSGraphResizeNearestRoundingModeRoundToOdd        =  5L,
};
#endif


- (MPSGraphTensor * _Nonnull) convolution3DWithSourceTensor:(MPSGraphTensor * _Nonnull) source
                                    weightsTensor:(MPSGraphTensor * _Nonnull) weights
                                       descriptor:(MPSGraphConvolution3DOpDescriptor * _Nonnull) descriptor
                                                      name:(NSString * _Nullable) name;

- (MPSGraphTensor * _Nonnull) convolution3DDataGradientWithIncomingGradientTensor:(MPSGraphTensor * _Nonnull) incomingGradient
                                                          weightsTensor:(MPSGraphTensor * _Nonnull) weights
                                                            outputShape:(MPSShape * _Nonnull) outputShape
                                           forwardConvolutionDescriptor:(MPSGraphConvolution3DOpDescriptor * _Nonnull) forwardConvolutionDescriptor
                                                                   name:(NSString * _Nullable) name;

- (MPSGraphTensor * _Nonnull) convolution3DDataGradientWithIncomingGradientTensor:(MPSGraphTensor * _Nonnull) gradient
                                                          weightsTensor:(MPSGraphTensor * _Nonnull) weights
                                                      outputShapeTensor:(MPSGraphTensor * _Nonnull) outputShapeTensor
                                           forwardConvolutionDescriptor:(MPSGraphConvolution3DOpDescriptor * _Nonnull) forwardConvolutionDescriptor
                                                                             name:(NSString * _Nullable) name;

- (MPSGraphTensor * _Nonnull)cumulativeSumWithTensor:(MPSGraphTensor * _Nonnull)tensor
                                                axis:(NSInteger)axis
                                                name:(NSString * _Nullable)name;

- (MPSGraphTensor * _Nonnull)sortWithTensor:(MPSGraphTensor * _Nonnull)tensor
                                       axis:(NSInteger)axis
                                       name:(NSString * _Nullable)name;

- (MPSGraphTensor * _Nonnull) sortWithTensor:(MPSGraphTensor * _Nonnull) tensor
                               axis:(NSInteger) axis
                         descending:(BOOL) descending
                               name:(NSString * _Nullable) name;

- (MPSGraphTensor * _Nonnull) sortWithTensor:(MPSGraphTensor * _Nonnull) tensor
                         axisTensor:(MPSGraphTensor * _Nonnull) axisTensor
                         descending:(BOOL) descending
                               name:(NSString * _Nullable) name;

- (MPSGraphTensor * _Nonnull) sortWithTensor:(MPSGraphTensor * _Nonnull) tensor
                         axisTensor:(MPSGraphTensor * _Nonnull) axisTensor
                               name:(NSString * _Nullable) name;

- (MPSGraphTensor * _Nonnull)argSortWithTensor:(MPSGraphTensor * _Nonnull)tensor
                                          axis:(NSInteger)axis
                                          name:(NSString * _Nullable)name;

- (MPSGraphTensor * _Nonnull) argSortWithTensor:(MPSGraphTensor * _Nonnull) tensor
                                  axis:(NSInteger) axis
                            descending:(BOOL) descending
                                  name:(NSString * _Nullable) name;

- (MPSGraphTensor * _Nonnull) argSortWithTensor:(MPSGraphTensor * _Nonnull) tensor
                           axisTensor:(MPSGraphTensor * _Nonnull) axisTensor
                           descending:(BOOL) descending
                                 name:(NSString * _Nullable) name;

- (MPSGraphTensor * _Nonnull) argSortWithTensor:(MPSGraphTensor * _Nonnull) tensor
                           axisTensor:(MPSGraphTensor * _Nonnull) axisTensor
                                 name:(NSString * _Nullable) name;

- (MPSGraphTensor * _Nonnull)inverseOfTensor:(MPSGraphTensor * _Nonnull) inputTensor
                                        name:(NSString * _Nullable)name;

- (MPSGraphTensor * _Nonnull) resizeNearestWithTensor:(MPSGraphTensor * _Nonnull) imagesTensor
                                           sizeTensor:(MPSGraphTensor * _Nonnull) size
                                  nearestRoundingMode:(MPSGraphResizeNearestRoundingMode) nearestRoundingMode
                                         centerResult:(BOOL) centerResult
                                         alignCorners:(BOOL) alignCorners
                                               layout:(MPSGraphTensorNamedDataLayout) layout
                                                 name:(NSString * _Nullable) name;

- (MPSGraphTensor * _Nonnull) resizeNearestWithTensor:(MPSGraphTensor * _Nonnull) imagesTensor
                                           sizeTensor:(MPSGraphTensor * _Nonnull) size
                                    scaleOffsetTensor:(MPSGraphTensor * _Nonnull) scaleOffset
                                  nearestRoundingMode:(MPSGraphResizeNearestRoundingMode) nearestRoundingMode
                                               layout:(MPSGraphTensorNamedDataLayout) layout
                                                 name:(NSString * _Nullable) name;

- (MPSGraphTensor * _Nonnull) resizeBilinearWithTensor:(MPSGraphTensor * _Nonnull) imagesTensor
                                            sizeTensor:(MPSGraphTensor * _Nonnull) size
                                          centerResult:(BOOL) centerResult
                                          alignCorners:(BOOL) alignCorners
                                                layout:(MPSGraphTensorNamedDataLayout) layout
                                                  name:(NSString * _Nullable) name;

- (MPSGraphTensor * _Nonnull) resizeBilinearWithTensor:(MPSGraphTensor * _Nonnull) imagesTensor
                                            sizeTensor:(MPSGraphTensor * _Nonnull) size
                                     scaleOffsetTensor:(MPSGraphTensor * _Nonnull) scaleOffset
                                                layout:(MPSGraphTensorNamedDataLayout) layout
                                                  name:(NSString * _Nullable) name;

- (MPSGraphTensor * _Nonnull) resizeNearestWithGradientTensor:(MPSGraphTensor * _Nonnull) gradient
                                                        input:(MPSGraphTensor * _Nonnull) input
                                          nearestRoundingMode:(MPSGraphResizeNearestRoundingMode) nearestRoundingMode
                                                 centerResult:(BOOL) centerResult
                                                 alignCorners:(BOOL) alignCorners
                                                       layout:(MPSGraphTensorNamedDataLayout) layout
                                                         name:(NSString * _Nullable) name;

- (MPSGraphTensor * _Nonnull) resizeNearestWithGradientTensor:(MPSGraphTensor * _Nonnull) gradient
                                                        input:(MPSGraphTensor * _Nonnull) input
                                            scaleOffsetTensor:(MPSGraphTensor * _Nonnull) scaleOffset
                                          nearestRoundingMode:(MPSGraphResizeNearestRoundingMode) nearestRoundingMode
                                                       layout:(MPSGraphTensorNamedDataLayout) layout
                                                         name:(NSString * _Nullable) name;

- (MPSGraphTensor * _Nonnull) resizeBilinearWithGradientTensor:(MPSGraphTensor * _Nonnull) gradient
                                                         input:(MPSGraphTensor * _Nonnull) input
                                                  centerResult:(BOOL) centerResult
                                                  alignCorners:(BOOL) alignCorners
                                                        layout:(MPSGraphTensorNamedDataLayout) layout
                                                          name:(NSString * _Nullable) name;

- (MPSGraphTensor * _Nonnull) resizeBilinearWithGradientTensor:(MPSGraphTensor * _Nonnull) gradient
                                                         input:(MPSGraphTensor * _Nonnull) input
                                             scaleOffsetTensor:(MPSGraphTensor * _Nonnull) scaleOffset
                                                        layout:(MPSGraphTensorNamedDataLayout) layout
                                                          name:(NSString * _Nullable) name;

- (MPSGraphTensor * _Nonnull) sampleGridWithSourceTensor:(MPSGraphTensor * _Nonnull) source
                                        coordinateTensor:(MPSGraphTensor * _Nonnull) coordinates
                                                  layout:(MPSGraphTensorNamedDataLayout) layout
                                    normalizeCoordinates:(BOOL) normalizeCoordinates
                                     relativeCoordinates:(BOOL) relativeCoordinates
                                            alignCorners:(BOOL) alignCorners
                                             paddingMode:(MPSGraphPaddingMode) paddingMode
                                            samplingMode:(MPSGraphResizeMode) samplingMode
                                           constantValue:(double) constantValue
                                                    name:(NSString * _Nullable) name;

- (MPSGraphTensor * _Nonnull) sampleGridWithSourceTensor:(MPSGraphTensor * _Nonnull) source
                                        coordinateTensor:(MPSGraphTensor * _Nonnull) coordinates
                                                  layout:(MPSGraphTensorNamedDataLayout) layout
                                    normalizeCoordinates:(BOOL) normalizeCoordinates
                                     relativeCoordinates:(BOOL) relativeCoordinates
                                            alignCorners:(BOOL) alignCorners
                                             paddingMode:(MPSGraphPaddingMode) paddingMode
                                     nearestRoundingMode:(MPSGraphResizeNearestRoundingMode) nearestRoundingMode
                                           constantValue:(double) constantValue
                                                    name:(NSString * _Nullable) name;
- (MPSGraphTensor * _Nonnull) truncateWithTensor:(MPSGraphTensor * _Nonnull) tensor
                                            name:(NSString * _Nullable) name;

@end
