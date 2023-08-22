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
    /* *  As CAPL has no 'defines' I had to use this approach here   * */
    /*******************************************************************/
    char  _CHOOSED_ECU;
    char  _GATEWAY_FLAG_STOP   = _OFF_;
    char  _GATEWAY_DIAG_CASE   = _DEFAULT_SESSION_;
    char  _CLUSTER_FLAG_STOP   = _OFF_;
    char  _CLUSTER_DIAG_CASE   = _DEFAULT_SESSION_;
    char  _DISPLAYFLAG_STOP    = _OFF_;
    char  _DISPLAY_DIAG_CASE   = _DEFAULT_SESSION_;
    char  _LIDAR_FLAG_STOP     = _OFF_;
    char  _LIDAR_DIAG_CASE     = _DEFAULT_SESSION_;    
    char  _HU_FLAG_STOP        = _OFF_;
    char  _HU_DIAG_CASE        = _DEFAULT_SESSION_;

    /*
        TESTR_PRESENT_TARGET 
    */
    char _GATEWAY_TARGET_TESTER_PRESENT     =   _DISABLED_;
    char _CLUSTER_TARGET_TESTER_PRESENT     =   _DISABLED_;
    char _DISPLAY_TARGET_TESTER_PRESENT     =   _DISABLED_;
    char _LIDAR_TARGET_TESTER_PRESENT       =   _DISABLED_;
    char _HU_TARGET_TESTER_PRESENT          =   _DISABLED_;

   
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