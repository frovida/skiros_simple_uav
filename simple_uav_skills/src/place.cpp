#include <skiros_lib_skill_dummy/place.h>

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
class PlaceUav : public Place
{
public:
    PlaceUav() : Place()
    {
        this->setSkillType("Place");
        this->setVersion("0.0.1");
    }
    ~PlaceUav(){}

    bool onInit()
    {
        Place::onInit();
        addPrecondition(newCondition("uav:Landed", false, "Robot"));
        addPrecondition(newCondition("uav:LowBattery", false, "Robot"));
        return true;
    }

    int preSense()
    {
        Place::preSense();
        return 1;
    }

    int postSense()
    {
        return 1;
    }

    int execute()
    {
        this->setProgress("Placing object.");
        ros::Duration(2.0).sleep(); //Fake an execution time...
        setAllPostConditions();
        return 1;
    }

private:
};

} // namespace

//Export
PLUGINLIB_EXPORT_CLASS(skiros_skill::PlaceUav, skiros_skill::SkillBase)
