/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2014, Francesco Rovida
 *	Robotics, Vision and Machine Intelligence Laboratory
 *  Aalborg University, Denmark
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Aalborg Universitet nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

#include <sstream>
#include "skiros_world_model/condition.h"
#include "skiros_common/param_handler.h"
#include "skiros_world_model/world_element.h"
#include "skiros_config/declared_uri.h"
#include <pluginlib/class_list_macros.h>//Plugin export library

using namespace skiros_config::owl;

namespace skiros
{
namespace condition
{
    class Landed :  public ConditionProperty<std::string>
    {
    public:

        Landed()
        { }

        void init(boost::shared_ptr<skiros_wm::WorldModelInterface> wm,
                  boost::shared_ptr<skiros_common::ParamHandler> ph,
                  bool desired_state,
                  std::string uav_key,
                  std::string not_used)
        {
            ConditionProperty<std::string>::init(wm,ph, desired_state, uav_key, not_used);
            setPropertyType("UavState");
            setPropertyValue("Landed");
            setDescription("["+getType()+"]Is uav '" + uav_key +"' landed?");
        }
        ~Landed(){}
    };

    class Fly :  public ConditionProperty<std::string>
    {
    public:

        Fly()
        { }

        void init(boost::shared_ptr<skiros_wm::WorldModelInterface> wm,
                  boost::shared_ptr<skiros_common::ParamHandler> ph,
                  bool desired_state,
                  std::string uav_key,
                  std::string not_used)
        {
            ConditionProperty<std::string>::init(wm,ph, desired_state, uav_key, not_used);
            setPropertyType("UavState");
            setPropertyValue("Flying");
            setDescription("["+getType()+"]Is uav '" + uav_key +"' flying?");
        }
        ~Fly(){}
    };

    class LowBattery :  public ConditionProperty<std::string>
    {
    public:

        LowBattery()
        { }

        void init(boost::shared_ptr<skiros_wm::WorldModelInterface> wm,
                  boost::shared_ptr<skiros_common::ParamHandler> ph,
                  bool desired_state,
                  std::string uav_key,
                  std::string not_used)
        {
            ConditionProperty<std::string>::init(wm,ph, desired_state, uav_key, not_used);
            setPropertyType("BatteryState");
            setPropertyValue("LowBattery");
            setDescription("["+getType()+"]Has uav '" + uav_key +"' low battery?");
        }
        ~LowBattery(){}
    };
}
}

//Export
PLUGINLIB_EXPORT_CLASS(skiros::condition::Landed, skiros::condition::ConditionBase)
PLUGINLIB_EXPORT_CLASS(skiros::condition::Fly, skiros::condition::ConditionBase)
PLUGINLIB_EXPORT_CLASS(skiros::condition::LowBattery, skiros::condition::ConditionBase)
