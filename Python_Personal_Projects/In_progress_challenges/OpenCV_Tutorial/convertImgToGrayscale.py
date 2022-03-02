from cv2 import GaussianBlur
import numpy as np
import cv2 as cv

# Read and show image
def showImage(filePath):
    img = cv.imread(filePath)
    cv.imshow("Cat", img)
    cv.waitKey(0)
    return img

def resizeShowImage(filePath):
    img = cv.imread(filePath)
    resized_image = rescaleFrame(img, .2)
    cv.imshow("Resized Image", resized_image)
    cv.waitKey(0)
    return resized_image



def rescaleFrame(frame, scale=0.75):
    width = int(frame.shape[1] * scale)
    height = int(frame.shape[0] * scale)
    dimensions = (width,height)
    return cv.resize(frame,dimensions, interpolation=cv.INTER_AREA)

def showImgInGrayScale(filePath):
    img = cv.imread(filePath)
    gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
    resized_image = rescaleFrame(gray, .2)
    cv.imshow("Cat", resized_image)
    cv.waitKey(0)
    return resized_image

def gaussianBlur(filePath):
    img = cv.imread(filePath)
    blur = cv.GaussianBlur(img, (133,133), cv.BORDER_DEFAULT)
    blurred_resized = rescaleFrame(blur, .2)
    cv.imshow("Blurred", blurred_resized)
    cv.waitKey(0)
    return blurred_resized


# Reduce amount of edge detected by applying blue before cascade
def edgeCascade(filePath):
    img = cv.imread(filePath)
    resized = rescaleFrame(img, .2)
    blurred = cv.GaussianBlur(resized, (1,1), cv.BORDER_DEFAULT)
    canny = cv.Canny(blurred, 125, 175)
    cv.imshow("Cat Edges", canny)
    cv.waitKey(0)
    return canny

def dilateImage(filePath):
    img = cv.imread(filePath)
    resized = rescaleFrame(img, .2)
    blurred = cv.GaussianBlur(resized, (1,1), cv.BORDER_DEFAULT)
    canny = cv.Canny(blurred, 125, 175)
    dilated = cv.dilate(canny, (3,3), iterations=6)
    cv.imshow("Dilated", dilated)
    cv.waitKey(0)
    return dilated

def resizeCrop(filePath):
    img = cv.imread(filePath)
    # resized = cv.resize(img, (500,500))
    cv.imshow("Resized", img)
    cv.waitKey(0)
    return img

showImage('Python_Personal_Projects\OpenCV\Photos\cat.jpg')
# resizeShowImage('Python_Personal_Projects\OpenCV\Photos\cat.jpg')
# showImgInGrayScale('Python_Personal_Projects\OpenCV\Photos\cat.jpg')
# gaussianBlur('Python_Personal_Projects\OpenCV\Photos\cat.jpg')
# edgeCascade('Python_Personal_Projects\OpenCV\Photos\WN.jpg')
# dilateImage("Python_Personal_Projects\OpenCV\Photos\WN.jpg")
# resizeCrop("Python_Personal_Projects\OpenCV\Photos\WN.jpg")