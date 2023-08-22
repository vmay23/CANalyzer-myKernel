/*@!Encoding:1252*/
variables{
    /*******************************************************************/
    /* *  As CAPL has no 'defines' I had to use this approach here   * */
    /*******************************************************************/
    /*
      TIMER event control
    */
    const int      T_10ms_      =     10;
    const int      T_50ms_      =     50;
    const int      T_100ms_     =    100;
    const int      T_150ms_     =    150;
    const int      T_200ms_     =    200;
    const int      T_250ms_     =    250;
    const int      T_300ms_     =    300;
    const int      T_350ms_     =    350;
    const int      T_400ms_     =    400;
    const int      T_450ms_     =    450;
    const int      T_500ms_     =    500;
    const int      T_700ms_     =    700;
    const int      T_750ms_     =    750;
    const int      T_1000ms_    =   1000;
    const int      T_1500ms_    =   1500;
    const int      T_2000ms_    =   2000;
    const int      T_2500ms_    =   2500;
    const int      T_VIN_TIMER_ =    500;


    /*
      ECU Control
    */
    const char _DISABLED_ = 0x00;                //is set when expecific ECU_TIME was choosed
    const char _ENABLED_  = 0x01;                //ootherwise, this ECU_TIME will be disabled
    const char _ON_       = 0x01;
    const char _OFF_      = 0x00; 



    /*
      DIAGNOSTIC SESSION CONTROL
    */  
    const   int   _T_STOP_MSG_               = 100;      //time to spent to shut up all messages from any ECU
    const   int   _T_TESTER_PRESENT_        = 2000;	     //tester present value
    const   char  _DEFAULT_SESSIO  N_       = 0x01;
    const   char  _EXTENDED_SESSION_        = 0x02;
    const   char  _TESTER_PRESENT_          = 0x03;
    const   char  _STOP_MESSAGE_            = 0x04;
    const   long  _STOP_ALL_MSG_      = 0x04280103;      //ISO14226 - UDS PROTOCOL   
    const   long  _START_ALL_MSG_     = 0x04280003;

    
    const   long _GATEWAY_DIAG_      = 0x98B414D3;       //gateway diagnostic address
    const   long _CLUSTER_DIAG_      = 0x98B4FAD3;
    const   long _DISPLAY_DIAG_      = 0x98B45BD3;
    const   long _LIDAR_DIAG_        = 0x98B47ED3;
    const   long _ECU_DIAG_          = 0x98B48CD3; 
  
    
    /*
      ECU ALIAS (shortname from diagnost address)
    */
    const char _GATEWAY_    =         0x14;
    const char _CLUSTER_    =         0xFA;
    const char _DISPLAY_    =         0x5B;
    const char _LIDAR_      =         0x7E;
    const char _HU_         =         0x8C;
    const char _ALL_ECU_    =         0xFF;              //mnemonic used to indicate that all ECUs will be used!

    /*________________________________________________________________________*/




    /*******************************************************************/
    /* *   variables ---> 1st must be configured before to be used   * */
    /*******************************************************************/
    char vin_part_can1 = 0x00;
    char vin_part_can2 = 0x00;
    
    char  _choosed_ecu;
    char  _GATEWAY_flag_stop   = _OFF_;
    char  _GATEWAY_diag_case   = _DEFAULT_SESSION_;
    char  _CLUSTER_flag_stop   = _OFF_;
    char  _CLUSTER_diag_case   = _DEFAULT_SESSION_;
    char  _DISPLAY_flag_stop   = _OFF_;
    char  _DISPLAY_diag_case   = _DEFAULT_SESSION_;
    char  _LIDAR_flag_stop     = _OFF_;
    char  _LIDAR_diag_case     = _DEFAULT_SESSION_;    
    char  _HU_flag_stop        = _OFF_;
    char  _HU_diag_case        = _DEFAULT_SESSION_;

    /*
        TESTR_PRESENT_TARGET 
    */
    char _GATEWAY_target_tester_present     =   _DISABLED_;
    char _CLUSTER_target_tester_present     =   _DISABLED_;
    char _DISPLAY_target_tester_present     =   _DISABLED_;
    char _LIDAR_target_tester_present       =   _DISABLED_;
    char _HU_target_tester_present          =   _DISABLED_;

    /*
        DIAGNOSTIC timers
    */
    msTimer t_tester_present;
       
    /*
        SERVICE 28
    */  
    msTimer t_stop_messages_gateway;
    msTimer t_stop_messages_cluster;
    msTimer t_stop_messages_display;
    msTimer t_stop_messages_lidar;
    msTimer t_stop_messages_hu;
    msTimer t_default_session;
    msTimer t_extended_session;
    msTimer t_shut_up_ecu;
  
    /*
        ecu message timers
    */
    msTimer    t_10ms;
    msTimer    t_50ms;
    msTimer    t_100ms;
    msTimer    t_150ms;
    msTimer    t_200ms;
    msTimer    t_250ms;
    msTimer    t_300ms;
    msTimer    t_350ms;
    msTimer    t_400ms;
    msTimer    t_450ms;
    msTimer    t_500ms;
    msTimer    t_700ms;
    msTimer    t_750ms;
    msTimer    t_1000ms;
    msTimer    t_1500ms;
    msTimer    t_2000ms; 
    msTimer    t_2500ms; 
    msTimer    t_vin;

    /*
        ECU TIMER TARGET 
    */
    //GATEWAY
    char _GATEWAY_TARGET;
    char _GATEWAY_TARGET_VIN;
    char _GATEWAY_TARGET_10;
    char _GATEWAY_TARGET_50;
    char _GATEWAY_TARGET_100; 
    char _GATEWAY_TARGET_150;
    char _GATEWAY_TARGET_200;
    char _GATEWAY_TARGET_250;
    char _GATEWAY_TARGET_300;
    char _GATEWAY_TARGET_350;
    char _GATEWAY_TARGET_400;
    char _GATEWAY_TARGET_450;
    char _GATEWAY_TARGET_500;
    char _GATEWAY_TARGET_700;
    char _GATEWAY_TARGET_750;
    char _GATEWAY_TARGET_1000;
    char _GATEWAY_TARGET_1500;
    char _GATEWAY_TARGET_2000;
    char _GATEWAY_TARGET_2500;

    //CLUSTER
    char _CLUSTER_TARGET;
    char _CLUSTER_TARGET_10;
    char _CLUSTER_TARGET_50;
    char _CLUSTER_TARGET_100; 
    char _CLUSTER_TARGET_150;
    char _CLUSTER_TARGET_200;
    char _CLUSTER_TARGET_250;
    char _CLUSTER_TARGET_300;
    char _CLUSTER_TARGET_350;
    char _CLUSTER_TARGET_400;
    char _CLUSTER_TARGET_450;
    char _CLUSTER_TARGET_500;
    char _CLUSTER_TARGET_700;
    char _CLUSTER_TARGET_750;
    char _CLUSTER_TARGET_1000;
    char _CLUSTER_TARGET_1500;
    char _CLUSTER_TARGET_2000;
    char _CLUSTER_TARGET_2500;

    //DISPLAY
    char _DISPLAY_TARGET;
    char _DISPLAY_TARGET_10;
    char _DISPLAY_TARGET_50;
    char _DISPLAY_TARGET_100; 
    char _DISPLAY_TARGET_150;
    char _DISPLAY_TARGET_200;
    char _DISPLAY_TARGET_250;
    char _DISPLAY_TARGET_300;
    char _DISPLAY_TARGET_350;
    char _DISPLAY_TARGET_400;
    char _DISPLAY_TARGET_450;
    char _DISPLAY_TARGET_500;
    char _DISPLAY_TARGET_700;
    char _DISPLAY_TARGET_750;
    char _DISPLAY_TARGET_1000;
    char _DISPLAY_TARGET_1500;
    char _DISPLAY_TARGET_2000;
    char _DISPLAY_TARGET_2500;

    //LIDAR
    char _LIDAR_TARGET;
    char _LIDAR_TARGET_10;
    char _LIDAR_TARGET_50;
    char _LIDAR_TARGET_100; 
    char _LIDAR_TARGET_150;
    char _LIDAR_TARGET_200;
    char _LIDAR_TARGET_250;
    char _LIDAR_TARGET_300;
    char _LIDAR_TARGET_350;
    char _LIDAR_TARGET_400;
    char _LIDAR_TARGET_450;
    char _LIDAR_TARGET_500;
    char _LIDAR_TARGET_700;
    char _LIDAR_TARGET_750;
    char _LIDAR_TARGET_1000;
    char _LIDAR_TARGET_1500;
    char _LIDAR_TARGET_2000;
    char _LIDAR_TARGET_2500;

    //HU
    char _HU_TARGET;
    char _HU_TARGET_10;
    char _HU_TARGET_50;
    char _HU_TARGET_100; 
    char _HU_TARGET_150;
    char _HU_TARGET_200;
    char _HU_TARGET_250;
    char _HU_TARGET_300;
    char _HU_TARGET_350;
    char _HU_TARGET_400;
    char _HU_TARGET_450;
    char _HU_TARGET_500;
    char _HU_TARGET_700;
    char _HU_TARGET_750;
    char _HU_TARGET_1000;
    char _HU_TARGET_1500;
    char _HU_TARGET_2000;
    char _HU_TARGET_2500;

}