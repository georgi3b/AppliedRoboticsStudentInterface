#include "student_image_elab_interface.hpp"
#include "student_planning_interface.hpp"
#include "visual_functions.hpp"
//#include "path_functions.hpp"
#include "dubins_functions.hpp"

namespace student {

// Debug variables
const bool DEBUG_Map = true;
const bool DEBUG_Robot = false;

	void loadImage(cv::Mat& img_out, const std::string& config_folder){

		student_loadImage(img_out, config_folder);

	}

	void genericImageListener(const cv::Mat& img_in, std::string topic, const std::string& config_folder){
		
		student_genericImageListener(img_in, topic, config_folder);

	}

	bool extrinsicCalib(const cv::Mat& img_in, std::vector<cv::Point3f> object_points, const cv::Mat& camera_matrix, cv::Mat& rvec, cv::Mat& tvec, const std::string& config_folder){
	
		return student_extrinsicCalib(img_in, object_points, camera_matrix, rvec, tvec, config_folder);
	
	}

	void imageUndistort(const cv::Mat& img_in, cv::Mat& img_out, 
			const cv::Mat& cam_matrix, const cv::Mat& dist_coeffs, const std::string& config_folder){

		student_imageUndistort(img_in, img_out, cam_matrix, dist_coeffs, config_folder);

	}

	void findPlaneTransform(const cv::Mat& cam_matrix, const cv::Mat& rvec, 
						const cv::Mat& tvec, const std::vector<cv::Point3f>& object_points_plane, 
						const std::vector<cv::Point2f>& dest_image_points_plane, 
						cv::Mat& plane_transf, const std::string& config_folder){

		student_findPlaneTransform(cam_matrix, rvec, tvec, object_points_plane, dest_image_points_plane,plane_transf,config_folder);
		std::cout << "\tstudent_findPlaneTransform COMPLETED.\n" << std::flush;
	}


	void unwarp(const cv::Mat& img_in, cv::Mat& img_out, const cv::Mat& transf, const std::string& config_folder) {

		student_unwarp(img_in, img_out, transf, config_folder);

	}

	bool processMap(const cv::Mat& img_in, const double scale, std::vector<Polygon>& obstacle_list, std::vector<std::pair<int,Polygon>>& victim_list, Polygon& gate, const std::string& config_folder){
		
		bool res = student_processMap(img_in, scale, obstacle_list, victim_list, gate, config_folder, DEBUG_Map);
		std::cout << "Inside processMap, size of offsetted_obstacles: " << offsetted_obstacles.size() << std::endl; // here, should be != 0

		return res;
	}

	bool findRobot(const cv::Mat& img_in, const double scale, Polygon& triangle, double& x, double& y, double& theta, const std::string& config_folder) {

		return student_findRobot(img_in, scale, triangle, x, y, theta, config_folder, DEBUG_Robot);

	}

	bool planPath(const Polygon& borders, const std::vector<Polygon>& obstacle_list, const std::vector<std::pair<int,Polygon>>& victim_list, const Polygon& gate, const float x, const float y, const float theta, Path& path){
		//throw std::logic_error( "STUDENT FUNCTION - PLAN PATH - NOT IMPLEMENTED" );
		
		std::cout << "Inside planPath, size of offsetted_obstacles: " << offsetted_obstacles.size() << std::endl;
		std::cout << "\tstudent_planPath COMPLETED.\n" << std::flush;
	}
}
	
