/**
Copyright (c) 2014, Manos Tsardoulias
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MANOS TSARDOULIAS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef ROS_NAO_JOINT_ANGLES_SPEED_WRAPPER
#define ROS_NAO_JOINT_ANGLES_SPEED_WRAPPER

#include "nao_utilities/includes.h"

//! @namespace ros_nao_utils
//! @brief Namespace for the ROS NAO wrappers
namespace ros_nao_utils
{
  
  typedef actionlib::SimpleActionClient<nao_msgs::JointAnglesWithSpeedAction> 
    Joint_a_c; 
  typedef nao_msgs::JointAnglesWithSpeedGoal Joint_a_goal; 
  
  //! @class Bumpers
  //! @brief Wrapper for NAO's bumpers module 
  class MotionController
  {
    protected:
    
      Joint_a_c *act_client_;
      
      ros::ServiceClient stiffness_on_service_client;
      ros::ServiceClient stiffness_off_service_client;

      //! @brief Default constructor 
      MotionController(void);
    
    public:

      //! @brief Virtual callback for the face detection event
      void make_movement(
        std::vector<std::string> joints,
        std::vector<float> angles,
        float speed,
        bool relative
      );
      
      void setStiffness(bool state);
  };
}
//~ 
#endif