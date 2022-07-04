#include <sys/types.h>

#define BANKER_RESULT_SUCCESS           0   // 成功向目标客户分配资源，或收回目标客户的资源
#define BANKER_RESULT_FAILED            -1  // 目标客户资源回收失败，或因为潜在危险而无法向客户分配资源
#define BANKER_RESULT_EXCEEDED          -2  // 目标客户请求释放的资源量超出当前持有量，或请求分配的资源超出自身持有上限，或已注册进程数达到上限
#define BANKER_RESULT_UNAVAILABLE       -3  // 目标客户请求的资源量或最大可能持有量大于当前系统可分配量
#define BANKER_RESULT_INVALID_PID       -4  // 客户 PID 无效（可能是因为该进程尚未注册），或者是为一个已经注册过的 PID 二次注册

/**
 * @brief 客户请求立即获取一系列资源。可能会阻塞调用进程
 * 
 * @param request 按照顺序，每个资源的请求量
 * @return int 请求的结果
 */
int request_resources(int request[]);

/**
 * @brief 客户请求立即释放一系列资源。可能会阻塞调用进程
 * 
 * @param request 按照顺序，每个资源的释放量
 * @return int 请求的结果
 */
int release_resources(int request[]);

/**
 * @brief 注册一个客户进程。可能会阻塞调用进程
 * 
 * @param maximum 按照顺序，每个资源的最大请求量
 * @return int 请求的结果
 */
int register_process(int maximum[]);