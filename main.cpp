/*@!Encoding:1252*/

/*
  This script was developped by @viniciusmay23 / @vmay23
  jobs.viniciusmay@gmail.com
  Sete Lagoas, 2023/08/23

*/

includes{
  //kernel-core  
    #include "/kernel-core/k_dbc.can"
    #include "/kernel-core/k_config.can"
    #include "/kernel-core/k_timersMan.can"
    #include "/kernel-core/k_ecuMatrix.can"
    
  //help2man
    #include "help2man/h2m_ignet_functions.can"
    #include "help2man/h2m_gateway_defaults.can"
    #include "help2man/h2m_cluster_defaults.can"
    #include "help2man/h2m_display_defaults.can"
    #include "help2man/h2m_lidar_defaults.can"
    #include "help2man/h2m_hu_defaults.can"

  //TEST_CASES
    #include "testcase/tc_keyON_keyOFF.can"
}


variables{

}


on start(){
    Matrix(_GATEWAY_);
}

on preStop(){
    KeyOff();
}


on *{
  output(this);
}
