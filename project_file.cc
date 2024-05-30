#include "ns3/command-line.h"
#include "ns3/constant-position-mobility-model.h"
#include "ns3/end-device-lora-phy.h"
#include "ns3/end-device-lorawan-mac.h"
#include "ns3/gateway-lora-phy.h"
#include "ns3/gateway-lorawan-mac.h"
#include "ns3/log.h"
#include "ns3/lora-helper.h"
#include "ns3/mobility-helper.h"
#include "ns3/node-container.h"
#include "ns3/one-shot-sender-helper.h"
#include "ns3/position-allocator.h"
#include "ns3/simulator.h"
#include "ns3/ns2-mobility-helper.h"

#include <algorithm>
#include <ctime>
#include <fstream>

using namespace ns3;
using namespace lorawan;

NS_LOG_COMPONENT_DEFINE("SimpleLoRaWANNetworkExample");

int main(int argc, char* argv[]) {
    // Set up logging
    LogComponentEnable("SimpleLoRaWANNetworkExample", LOG_LEVEL_ALL);
    LogComponentEnable("LoraChannel", LOG_LEVEL_INFO);
    LogComponentEnable("LoraPhy", LOG_LEVEL_ALL);
    LogComponentEnable("EndDeviceLoraPhy", LOG_LEVEL_ALL);
    LogComponentEnable("GatewayLoraPhy", LOG_LEVEL_ALL);
    LogComponentEnable("LoraInterferenceHelper", LOG_LEVEL_ALL);
    LogComponentEnable("LorawanMac", LOG_LEVEL_ALL);
    LogComponentEnable("EndDeviceLorawanMac", LOG_LEVEL_ALL);
    LogComponentEnable("ClassAEndDeviceLorawanMac", LOG_LEVEL_ALL);
    LogComponentEnable("GatewayLorawanMac", LOG_LEVEL_ALL);
    LogComponentEnable("LogicalLoraChannelHelper", LOG_LEVEL_ALL);
    LogComponentEnable("LogicalLoraChannel", LOG_LEVEL_ALL);
    LogComponentEnable("LoraHelper", LOG_LEVEL_ALL);
    LogComponentEnable("LoraPhyHelper", LOG_LEVEL_ALL);
    LogComponentEnable("LorawanMacHelper", LOG_LEVEL_ALL);
    LogComponentEnable("OneShotSenderHelper", LOG_LEVEL_ALL);
    LogComponentEnable("OneShotSender", LOG_LEVEL_ALL);
    LogComponentEnable("LorawanMacHeader", LOG_LEVEL_ALL);
    LogComponentEnable("LoraFrameHeader", LOG_LEVEL_ALL);
    LogComponentEnableAll(LOG_PREFIX_FUNC);
    LogComponentEnableAll(LOG_PREFIX_NODE);
    LogComponentEnableAll(LOG_PREFIX_TIME);

    /************************
     *  Create the channel  *
     ************************/

    NS_LOG_INFO("Creating the channel...");

    // Create the lora channel object
    Ptr<LogDistancePropagationLossModel> loss = CreateObject<LogDistancePropagationLossModel>();
    loss->SetPathLossExponent(3.76);
    loss->SetReference(1, 7.7);

    Ptr<PropagationDelayModel> delay = CreateObject<ConstantSpeedPropagationDelayModel>();

    Ptr<LoraChannel> channel = CreateObject<LoraChannel>(loss, delay);

    /************************
     *  Create the helpers  *
     ************************/

    NS_LOG_INFO("Setting up helpers...");

    // Create the LoraPhyHelper
    LoraPhyHelper phyHelper = LoraPhyHelper();
    phyHelper.SetChannel(channel);

    // Create the LorawanMacHelper
    LorawanMacHelper macHelper = LorawanMacHelper();

    // Create the LoraHelper
    LoraHelper helper = LoraHelper();

    /************************
     *  Create End Devices  *
     ************************/

    NS_LOG_INFO("Creating the end device...");

    // Create a set of nodes
    NodeContainer endDevices;
    endDevices.Create(1);

    // Assign a mobility model to the nodes using NS2 mobility helper
    Ns2MobilityHelper ns2 = Ns2MobilityHelper("/home/semih/ns-allinone-3.41/ns-3.41/bursa_map.tcl");
    ns2.Install();

    // Create the LoraNetDevices of the end devices
    phyHelper.SetDeviceType(LoraPhyHelper::ED);
    macHelper.SetDeviceType(LorawanMacHelper::ED_A);
    helper.Install(phyHelper, macHelper, endDevices);

    /*********************
     *  Create Gateways  *
     *********************/

    NS_LOG_INFO("Creating the gateway...");
    NodeContainer gateways;
    gateways.Create(1);

    // Gateways typically have fixed positions, so we use a constant position model here
    MobilityHelper mobility;
    Ptr<ListPositionAllocator> allocator = CreateObject<ListPositionAllocator>();
    allocator->Add(Vector(0, 0, 0)); // Example position, adjust as needed
    mobility.SetPositionAllocator(allocator);
    mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
    mobility.Install(gateways);

    // Create a netdevice for each gateway
    phyHelper.SetDeviceType(LoraPhyHelper::GW);
    macHelper.SetDeviceType(LorawanMacHelper::GW);
    helper.Install(phyHelper, macHelper, gateways);

    /*********************************************
     *  Install applications on the end devices  *
     *********************************************/

    OneShotSenderHelper oneShotSenderHelper;
    oneShotSenderHelper.SetSendTime(Seconds(2));

    oneShotSenderHelper.Install(endDevices);

    /******************
     * Set Data Rates *
     ******************/
    std::vector<int> sfQuantity(6);
    sfQuantity = LorawanMacHelper::SetSpreadingFactorsUp(endDevices, gateways, channel);

    /****************
     *  Simulation  *
     ****************/

    Simulator::Stop(Hours(2));

    Simulator::Run();

    Simulator::Destroy();

    /****************
     *  Export Data  *
     ****************/

    // Export simulation data to XML file
    std::ofstream xmlFile("simulation_results.xml");
    if (xmlFile.is_open()) {
        xmlFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
        xmlFile << "<simulation>" << std::endl;
        xmlFile << "    <summary>" << std::endl;
        xmlFile << "        <runtime>2 hours</runtime>" << std::endl;
        xmlFile << "    </summary>" << std::endl;
        xmlFile << "    <spreading_factors>" << std::endl;
        for (size_t i = 0; i < sfQuantity.size(); ++i) {
            xmlFile << "        <sf_" << i + 7 << ">" << sfQuantity[i] << "</sf_" << i + 7 << ">" << std::endl;
        }
        xmlFile << "    </spreading_factors>" << std::endl;
        xmlFile << "</simulation>" << std::endl;
        xmlFile.close();
        NS_LOG_INFO("Simulation results exported to 'simulation_results.xml'");
    } else {
        NS_LOG_ERROR("Unable to open file 'simulation_results.xml' for writing!");
    }

    return 0;
}