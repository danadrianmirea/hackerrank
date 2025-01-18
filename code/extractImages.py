import cv2
import os

def extract_frames(video_path, interval=30):
    # Get the base name of the video without the extension
    video_name = os.path.splitext(os.path.basename(video_path))[0]
    
    # Open the video file
    cap = cv2.VideoCapture(video_path)
    
    # Check if the video was successfully opened
    if not cap.isOpened():
        print(f"Error: Could not open video file {video_path}")
        return
    
    # Get video properties
    fps = int(cap.get(cv2.CAP_PROP_FPS))  # Frames per second
    frame_count = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))  # Total number of frames
    duration = frame_count / fps  # Duration in seconds
    
    print(f"Video: {video_path}")
    print(f"Duration: {duration:.2f} seconds, FPS: {fps}, Total Frames: {frame_count}")
    
    # Calculate the frame interval in terms of frames
    frame_interval = interval * fps
    
    frame_number = 0
    saved_frame_count = 0
    
    # Loop through the video frames
    while cap.isOpened():
        ret, frame = cap.read()
        
        # Break if no more frames are available
        if not ret:
            break
        
        # Save the frame if it's at the desired interval
        if frame_number % frame_interval == 0:
            frame_filename = f"{video_name}_frame_{saved_frame_count}.jpg"
            cv2.imwrite(frame_filename, frame)
            print(f"Saved: {frame_filename}")
            saved_frame_count += 1
        
        frame_number += 1
    
    # Release the video capture object
    cap.release()
    print("Frame extraction complete.")

# Replace with your video file path
video_file = "example.mp4"
extract_frames(video_file, interval=30)