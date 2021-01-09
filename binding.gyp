{
  "targets": [
    {
      "target_name": "opencv-application",
      "include_dirs": ["$(OPENCV_DIR)\\..\\..\\include"],
      "sources": ["OpenCVApplication.cpp"],
      "libraries": ["$(OPENCV_DIR)\\lib\\opencv_world412.lib"]
    }
  ]
}
