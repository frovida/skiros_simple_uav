#include <skiros_lib_skill_dummy/drive.h>

namespace skiros_skill
{
using namespace skiros_config::owl;
using namespace skiros_wm;

/*!
 * \brief A fake drive. Move a 'MobileBase' element to a selected location
 *
 * Teach required: \n
 * Pre-condition:  \n
 * Post-condition: \n
 * Failures: \n
 *  Never fail. \n
 *
 */
class DriveUav : public Drive
{
public:
    DriveUav() : Drive()
    {
        this->setSkillType("Drive");
        this->setDescription("Fake drive. Move the robot close to a selected container");
        this->setVersion("0.0.1");
    }
    ~DriveUav(){}

    bool onInit()
    {
        Drive::onInit();
        addPrecondition(newCondition("uav:Landed", false, "Robot"));
        addPrecondition(newCondition("uav:LowBattery", false, "Robot"));
        return true;
    }

    int preSense()
    {
        Drive::preSense();
        return 1;
    }

    int postSense()
    {
        return 1;
    }

    int execute()
    {
        this->setProgress("Drive to container.");
        ros::Duration(2.0).sleep(); //Fake an execution time...
        getWorldHandle()->setRelation(mobile_base_.id(), relation::Str[relation::robotAt], initial_location_.id(), false);
        setAllPostConditions();
        return 1;
    }

private:
};

} // namespace

//Export
PLUGINLIB_EXPORT_CLASS(skiros_skill::DriveUav, skiros_skill::SkillBase)
