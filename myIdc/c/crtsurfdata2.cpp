/*
 * description: crtsurfdata2.cpp 本程序用于生成全国气象站点观测的分钟数据
 * author: song zhuozhu 
 */

#include "_public.h"

// 省   站号  站名 纬度   经度  海拔高度
// 安徽, 58015, 砀山, 34.27, 116.2, 44.2

struct st_stcode
{
  char provname[31]; // 省
  char obtid[11];    // 站号
  char obtname[31];  // 站名
  double lat;        // 纬度
  double lon;        // 经度
  double height;     // 海拔高度
};

// 存放全国气象站点参数的容器
vector<st_stcode> vstcode;

// 把站点参数文件加载到vstcode容器中
bool LoadSTCode(const char* inifile);


CLogFile logfile(10); // 日志类, 一般定义为全局变量

int main(int argc, char *argv[])
{
  // inifile outpath logfile
  if (argc != 4)
  {
    printf("Using:./crtsurfdata1 inifile outpath logfile\n");
    printf("Example:/szz/project/myIdc/bin/crtsurfdata2 /szz/project/myIdc/ini/stcode.ini /tmp/surfdata /log/idc/crtsurfdata.log\n\n");

    printf("inifle 全国气象站点参数文件名。\n");
    printf("outpath 全国气象站点数据文件存放的目录。\n");
    printf("logfile 本程序运行的日志文件名。\n");

    return -1;
  }

  if (logfile.Open(argv[3], "a+", false) == false)
  {
    printf("logfile.Open(%s) failed.\n", argv[3]);
    return -1;
  }

  logfile.Write("crtsurfdata1 开始运行。\n");

  // 写入业务逻辑代码

  if (LoadSTCode(argv[1]) == false) return -1;

  logfile.Write("crtsurfdata1 运行结束。\n");
  logfile.WriteEx("crtsurfdata1 运行结束。");

  return 0;
}



// 把站点参数文件加载到vstcode容器中
bool LoadSTCode(const char* inifile)
{
  CFile File;

  // 打开站点参数文件
  if (File.Open(inifile, "r") == false)
  {
    // 文件打开失败，返回false
    logfile.Write("File.Open(%s) failed.\n", inifile);
    return false;
  }

  char strBuffer[301];

  while (true)
  {
    // 从站点参数文件中读取一行，如果已经读取完，跳出循环
    if (File.Fgets(strBuffer, 300, true) == false)
      break;

    // 把读取到的一行拆分

    // 把站点参数的每个数据项保存到站点参数结构体中

    // 把站点参数结构体放入站点参数容器
  }

  // 关闭文件

  return true;
}