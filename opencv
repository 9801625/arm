import pyrealsense2 as rs
import numpy as np
import cv2

# カメラ初期化
pipeline = rs.pipeline()
config = rs.config()

config.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 30)
config.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)

pipeline.start(config)

while True:
    frames = pipeline.wait_for_frames()

    depth_frame = frames.get_depth_frame()
    color_frame = frames.get_color_frame()

    depth_image = np.asanyarray(depth_frame.get_data())
    color_image = np.asanyarray(color_frame.get_data())

    # 中央の距離取得
    x = 320
    y = 240
    distance = depth_frame.get_distance(x, y)

    print("distance:", distance, "m")

    cv2.circle(color_image, (x, y), 5, (0,0,255), -1)
    cv2.imshow("color", color_image)

    if cv2.waitKey(1) == 27:
        break

pipeline.stop()
cv2.destroyAllWindows()
