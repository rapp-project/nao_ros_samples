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

#ifndef NAO_TESTBED_VOCAL_COMMANDS_POSTURE_CHANGE_MODULE
#define NAO_TESTBED_VOCAL_COMMANDS_POSTURE_CHANGE_MODULE

#include <nao_utilities/nao_speech.h>
#include <nao_utilities/nao_bumpers.h>
#include <nao_utilities/nao_motion_controller.h>

enum STATE
{
  NORMAL,
  PROMPT
};

class Module : 
  public ros_nao_utils::Bumpers,
  public ros_nao_utils::Speech,
  public ros_nao_utils::MotionController
{
  private:
    
    ros::NodeHandle nh_;
    
    STATE state_;
    
    std::vector<std::string> commands;
    
    void serveCommand(std::string command);
    
  public:
    
    Module(void);
    
    virtual void tactile_callback(const nao_msgs::TactileTouch& msg);
    
    virtual void wordRecognizedCallback(const nao_msgs::WordRecognized& msg);
};

#endif
