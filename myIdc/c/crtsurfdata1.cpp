/*
 * description: crtsurfdata1.cpp 本程序用于生成全国气象站点观测的分钟数据
 * author: songzhuozhu
*/


#include "_public.h"

CLogFile logfile(10); // 日志类一般定义为全局变量


int main(int argc, char*argv[])
{
  // inifile outpath logfile 
  if (argc != 4)
  {
    printf("Using:./crtsurfdata1 inifile outpath logfile\n");
    printf("Example:/szz/project/myIdc/bin/crtsurfdata1 /szz/project/myIdc/ini/stcode.ini /tmp/surfdata /log/idc/crtsurfdata.log\n\n");

    printf("inifle 全国气象站点参数文件名。\n");
    printf("outpath 全国气象站点数据文件存放的目录。\n");
    printf("logfile 本程序运行的日志文件名。\n");

    return -1;
  }

  if (logfile.Open(argv[3],"a+",false) == false)
  {
    printf("logfile.Open(%s) failed.\n",argv[3]);
    return -1;
  }

  logfile.Write("crtsurfdata1 开始运行。\n");

  // 写入业务逻辑代码
  
  logfile.Write("crtsurfdata1 运行结束。\n");
  logfile.WriteEx("crtsurfdata1 运行结束。");



  return 0;
}