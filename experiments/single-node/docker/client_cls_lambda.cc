#include <iostream>
#include <errno.h>

#include "test.h"
//#include "/gtest/gtest.h"
#include "/gtest-master/include/gtest/gtest.h"

using namespace librados;

TEST(ClsSDK, TestSDKCoverageWrite) {
  
/*
  Rados cluster;
  std::string pool_name = get_temp_pool_name();
  ASSERT_EQ("", create_one_pool_pp(pool_name, cluster));
  IoCtx ioctx;
  cluster.ioctx_create(pool_name.c_str(), ioctx);
*/
  Rados cluster;
  IoCtx ioctx; 
  std::string pool_name("First_Pool");
  cluster.ioctx_create(pool_name.c_str(), ioctx);
  cluster.connect();

  bufferlist in, out;
  ASSERT_EQ(0, ioctx.exec("myobject", "sdk", "test_coverage_write", in, out));

  // Cleanup
  ioctx.close();
  cluster.shutdown();

 // ASSERT_EQ(0, destroy_one_pool_pp(pool_name, cluster));
}

TEST(ClsSDK, TestSDKCoverageReplay) {
  
  /*
  Rados cluster;
  std::string pool_name = get_temp_pool_name();
  ASSERT_EQ("", create_one_pool_pp(pool_name, cluster));
  IoCtx ioctx;
  cluster.ioctx_create(pool_name.c_str(), ioctx);
  */

  Rados cluster;	
  IoCtx ioctx;
  std::string pool_name("First_Pool");
  cluster.ioctx_create(pool_name.c_str(), ioctx);
 
  cluster.connect();
  bufferlist in, out;
  ASSERT_EQ(0, ioctx.exec("myobject", "sdk", "test_coverage_write", in, out));
  ASSERT_EQ(0, ioctx.exec("myobject", "sdk", "test_coverage_replay", in, out));

  // Cleanup
  ioctx.close();
  cluster.shutdown();
  //ASSERT_EQ(0, destroy_one_pool_pp(pool_name, cluster));
}
