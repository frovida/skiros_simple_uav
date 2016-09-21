#include <skiros_lib_skill_dummy/pick.h>

namespace skiros_skill
{
using namespace skiros_config::owl;
using namespace skiros_wm;

/*!
 * \brief Transfer a 'Product' element from the container to the gripper
 *
 * Teach required: TODO \n
 * Pre-condition: container has a Element subtype of 'Product' as child \n
 * Post-condition: a random element in the container is transfered in the gripper, using a pre-teached grasping pose. \n
 * Additional Params: \n
 *  TODO \n
 * Failures: \n
 *  TODO \n
 *
 */
class PickUav : public Pick
{
public:
    PickUav() : Pick()
    {
        this->setSkillType("Pick");
        this->setVersion("0.0.1");

    }
    ~PickUav(){}

    bool onInit()
    {
        Pick::onInit();
        addPrecondition(newCondition("uav:Landed", false, "Robot"));
        addPrecondition(newCondition("uav:LowBattery", false, "Robot"));
        return true;
    }

    int preSense()
    {
        Pick::preSense();
        return 1;
    }

    int postSense()
    {
        return 1;
    }

    int execute()
    {
        this->setProgress("Picking object.");
        ros::Duration(2.0).sleep(); //Fake an execution time...
        setAllPostConditions();
        return 1;
    }


private:
};

} // namespace

//Export
PLUGINLIB_EXPORT_CLASS(skiros_skill::PickUav, skiros_skill::SkillBase)
