#include "student_image_elab_interface.hpp"
#include "student_planning_interface.hpp"
#include "visual_functions.hpp"

namespace student {

	/**
	* Implementation of the imageUndistort() function of student_interface. It takes the 
	* img_in and performs the undistortion based on the camera parameters.
	*
	*/
	void student_imageUndistort(const cv::Mat& img_in, cv::Mat& img_out, 
  							    const cv::Mat& cam_matrix, const cv::Mat& dist_coeffs,
  						   		const std::string& config_folder) {

		// Utility/debug variables
		static bool initialized = false;
    	static cv::Mat output_map1, output_map2;

    	if (!initialized) {
    		std::cout << "\tFIRST FRAME RECEIVED... \n" << std::flush;

			cv::Mat R;
			try {
				cv::initUndistortRectifyMap(cam_matrix, dist_coeffs, R, cam_matrix, 
    	                            img_in.size(), CV_16SC2, output_map1, output_map2);
			}
			catch (const cv::Exception& e) {
				std::cerr << "ERROR IN METHOD <initUndistortRectifyMap> of student_imageUndistort.cpp: " << e.msg << std::endl;	// doesn't work with both cam_matrix replaced by R
				return;
			}

			std::cout << "\tstudent_imageUndistort INITIALIZED.\n" << std::flush;
			initialized = true;
    	}

		// Undistort the image
		try {
			cv::remap(img_in, img_out, output_map1, output_map2, cv::INTER_LINEAR);
		}
		catch (const cv::Exception& e) {
			std::cerr << "ERROR IN METHOD <remap> of student_imageUndistort.cpp: " << e.msg << std::endl;
			return;
		}
	}
}