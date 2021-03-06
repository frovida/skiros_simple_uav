//---------- Mandatory skill's include ----------
#include <pluginlib/class_list_macros.h>//Plugin export library
#include <ros/ros.h>
#include "skiros_skill/skill_base.h"    //Base template for all skills
#include "skiros_common/logger_sys.h"   //Skiros logging system
#include "skiros_config/param_types.h"  //Default parameters
#include "skiros_config/declared_uri.h" //Default world model URIs (Unified Resource Identifier) -> generated by skiros_world_model/generate_uri
//---------- Mandatory skill's include end ----------

namespace skiros_skill
{
using namespace skiros_config::owl;
using namespace skiros_wm;

/*!
 * \brief TODO
 *
 * Teach required: TODO \n
 * Pre-condition: TODO \n
 * Post-condition: TODO \n
 * Additional Params: \n
 *  TODO \n
 * Failures: \n
 *  TODO \n
 *
 */
class FlyAltitude : public SkillBase
{
public:
    FlyAltitude()
    {
        this->setSkillType("Drive");
        this->setVersion("0.0.1");
        getParamHandle()->addParamWithDefaultValue("Robot",
                                                  skiros_wm::Element(concept::Str[concept::Robot]),
                                                  "Robot to control",
                                                  skiros_common::online);
        getParamHandle()->addParamWithDefaultValue("Altitude",
                                                  1.0,
                                                  "Altitude to reach (meters)",
                                                  skiros_common::offline);
    }
    ~FlyAltitude(){}

    bool onInit()
    {
        addPrecondition(newCondition("uav:LowBattery", false, "Robot"));
        addPostcondition("NotLanded", newCondition("uav:Landed", false, "Robot"));
        return true;
    }

    int preSense()
    {
        skiros::Module monitor(getModulesHandler(),"monitor_battery", this->skillType());
        monitor.setParam("Robot", getParamHandle()->getParamValue<Element>("Robot"));
        monitor.setParam("f", 10.0);
        monitor.exe();
        return 1;
    }

    int postSense()
    {
        return 1;
    }

    int execute()
    {
        double altitude = getParamHandle()->getParamValue<double>("Altitude");
        this->setProgress("Going to altitude " + std::to_string(altitude));
        ros::Duration(2.0).sleep(); //Fake an execution time...
        setAllPostConditions();
        return 1;
    }

private:
};

} // namespace

//Export
PLUGINLIB_EXPORT_CLASS(skiros_skill::FlyAltitude, skiros_skill::SkillBase)
