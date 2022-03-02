import cv2 as cv
import numpy as np

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
    return img


def rescaleFrame(frame, scale=0.75):
    width = int(frame.shape[1] * scale)
    height = int(frame.shape[0] * scale)

    dimensions = (width,height)

    return cv.resize(frame,dimensions, interpolation=cv.INTER_AREA)

# showImage('Python_Personal_Projects\OpenCV\Photos\cat.jpg')
# resizeShowImage('Python_Personal_Projects\OpenCV\Photos\cat.jpg')

# Read and show Video
def playVideo(filePath):
    capture = cv.VideoCapture(filePath)

    while True:
        isTrue, frame = capture.read()
        cv.imshow("Video", frame)

        if cv.waitKey(1) == ord('q'):
            break

    capture.release()
    cv.destroyAllWindows()

# playVideo(0)



