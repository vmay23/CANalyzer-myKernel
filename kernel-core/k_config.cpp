/*@!Encoding:1252*/
variables{
    /******************************************************************************************************************************/
    /* *                                               CAN-BUS1 --- 500kbps                                                    * */
    /******************************************************************************************************************************/	 
    
    /*
        DIAGNOSTIC ADDRESS
    */
        MESSAGE DIAGNOSTIC_REQUEST_GATEWAY       MY_DIAGNOSTIC_REQUEST_GATEWAY;
        MESSAGE DIAGNOSTIC_REQUEST_CLUSTER       MY_DIAGNOSTIC_REQUEST_CLUSTER;
        MESSAGE DIAGNOSTIC_REQUEST_LIDAR         MY_DIAGNOSTIC_REQUEST_LIDAR;



    //---------------------------- DBC CAN1 cyclic messages ------------------------------------------//

    /*
        CYCLIC: 2000ms
    */                                                                          
        //ORIGINAL_NAME                         CLONE_NAME                      MESSAGE_ADDRESS     SENDER_BY    SEND_TO    
        MESSAGE CAN-BUS1::GATEWAY_STS_ENG       MY_CAN1_GATEWAY_STS_ENG;        //0x4aa             gateway      cluster,lidar


    /*
        CYCLIC: 1000ms
    */
        //ORIGINAL_NAME                         CLONE_NAME                      MESSAGE_ADDRESS     SENDER_BY    SEND_TO     
        MESSAGE CAN-BUS1::GATEWAY_STS_DOORS     MY_CAN1_GATEWAY_STS_DOORS;      //0x4ab             gateway      cluster
        MESSAGE CAN-BUS1::ODOMETER              MY_CAN1_ODOMETER                //0x3ae             cluster      gateway
        MESSAGE CAN-BUS1::TRIP_STATUS           MY_CCAN1_TRIP_STATUS            //0x8ac             gateway      cluster


    /*
        CYCLIC: 500ms
    */
        //ORIGINAL_NAME                         CLONE_NAME                      MESSAGE_ADDRESS     SENDER_BY    SEND_TO     
        MESSAGE CAN-BUS1::VIN                   MY_CAN1_VIN;                    //0x4ae             gateway      cluster, lidar
        MESSAGE CAN-BUS1::SPEED                 MY_CAN1_SPEED;                  //0xa33             gateway      cluster, lidar
        MESSAGE CAN-BUS1::RPM                   MY_CAN1_RPM;                    //0xab5             gateway      cluster


    /*
        CYCLIC: 100ms
    */
        //ORIGINAL_NAME                         CLONE_NAME                      MESSAGE_ADDRESS     SENDER_BY    SEND_TO     
        MESSAGE CAN-BUS1::BRAKE_STS             MY_CAN1_BRAKE_STS;              //0x1ac             gateway      cluster, lidar  
        MESSAGE CAN-BUS1::CRASH_WARNING         MY_CAN1_CRASH_WARNING;          //0x12f             lidar        gateway, cluster
        MESSAGE CAN-BUS1::CHIMES                MY_CAN2_CHIMES;                 //0x1ab             gateway      cluster, lidar
    /*____________________________________________________________________________________________________________________________*/










    /******************************************************************************************************************************/
    /* *                                               CAN-BUS2 --- 125kbps                                                    * */
    /******************************************************************************************************************************/	 
    
    /*
        DIAGNOSTIC ADDRESS
    */
        MESSAGE DIAGNOSTIC_REQUEST_HU            MY_DIAGNOSTIC_REQUEST_HU;
        MESSAGE DIAGNOSTIC_REQUEST_DISPLAY       MY_DIAGNOSTIC_REQUEST_DISPLAY;



    //---------------------------- DBC CAN2 cyclic messages ------------------------------------------//

    /*
        CYCLIC: 2000ms
    */                                                                          
        //ORIGINAL_NAME                         CLONE_NAME                      MESSAGE_ADDRESS     SENDER_BY    SEND_TO    
        MESSAGE CAN-BUS2::GATEWAY_STS_ENG       MY_CAN2_GATEWAY_STS_ENG;        //0x4af             gateway      hu, cluster


    /*
        CYCLIC: 1000ms
    */
        //ORIGINAL_NAME                         CLONE_NAME                      MESSAGE_ADDRESS     SENDER_BY    SEND_TO     
        MESSAGE CAN-BUS2::GATEWAY_STS_DOORS     MY_CAN2_GATEWAY_STS_DOORS;      //0x4fb             gateway      hu, cluster
        MESSAGE CAN-BUS2::TRIP_STATUS           MY_CAN2_TRIP_STATUS;            //0x555             cluster      hu


    /*
        CYCLIC: 500ms
    */
        //ORIGINAL_NAME                         CLONE_NAME                      MESSAGE_ADDRESS     SENDER_BY    SEND_TO     
        MESSAGE CAN-BUS2::VIN                   MY_CAN2_VIN;                    //0x3bb             gateway      hu, cluster
        MESSAGE CAN-BUS2::SPEED                 MY_CAN2_SPEED;                  //0xa33             gateway      hu, cluster


    /*
        CYCLIC: 100ms
    */
        //ORIGINAL_NAME                         CLONE_NAME                      MESSAGE_ADDRESS     SENDER_BY    SEND_TO     
        MESSAGE CAN-BUS2::BRAKE_STS             MY_CAN2_BRAKE_STS;              //0x1ac             gateway      hu, cluster  
        MESSAGE CAN-BUS2::CRASH_WARNING         MY_CAN2_CRASH_WARNING;          //0x12f             lidar        gateway, cluster, hu   
        MESSAGE CAN-BUS2::HU_CHIMES             MY_CAN2_HU_CHIMES;              //0x1ab             hu           gateway, display
        MESSAGE CAN-BUS2::HU_STATUS             MY_CAN2_HU_STATUS;              //0x6ed             hu           gateway, display, ipc
        MESSAGE CAN-BUS2::DISPLAY_STATUS        MY_CAN2_DISPLAY_STATUS;         //0xcc7             display      hu

    /*____________________________________________________________________________________________________________________________*/
}