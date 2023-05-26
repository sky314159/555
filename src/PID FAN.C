#include <stdio.h>

// 定义PID结构体
typedef struct {
    double kp; // 比例增益
    double ki; // 积分增益
    double kd; // 微分增益
    double setpoint; // 设定值
    double integral; // 积分项
    double pre_error; // 上一次误差
} PID;

// 初始化PID控制器
void pid_init(PID *pid, double kp, double ki, double kd, double setpoint) {
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;
    pid->setpoint = setpoint;
    pid->integral = 0;
    pid->pre_error = 0;
}

// 更新PID控制器状态并计算输出值
double pid_update(PID *pid, double measured_value, double dt) {
    // 计算误差
    double error = pid->setpoint - measured_value;
    // 更新积分项
    pid->integral += error * dt;
    // 计算微分项
    double derivative = (error - pid->pre_error) / dt;
    // 计算输出值
    double output = pid->kp * error + pid->ki * pid->integral + pid->kd * derivative;
    // 更新上一次误差
    pid->pre_error = error;
    return output;
}

// 设置风扇速度的函数，需要根据实际情况实现
void set_fan_speed(double speed) {
}

int main() {
    PID pid;
    // 初始化PID控制器，设定温度为25摄氏度
    pid_init(&pid, 1.0, 0.1, 0.5, 25.0);

    // 初始温度为30摄氏度
    double measured_temperature = 30.0;
    for (int i = 0; i < 10; i++) {
        printf("Measured temperature: %f\n", measured_temperature);
        // 计算输出值
        double output = pid_update(&pid, measured_temperature, 1.0);
        printf("Output: %f\n", output);
        // 设置风扇速度
        set_fan_speed(output);
        // 假设风扇降温效果与输出值成正比
        measured_temperature -= output;
    }
}
/*这个代码定义了一个`PID`结构体，包含了比例增益、积分增益、微分增益、设定值、积分项和上一次误差等成员。`pid_init`函数用于初始化PID控制器，`pid_update`函数用于根据测量值和时间间隔更新PID控制器的状态并计算输出值。

在`main`函数中，我们创建了一个`PID`控制器并进行了初始化，然后在循环中不断更新测量温度并调用`pid_update`函数计算输出值。根据输出值，我们调用`set_fan_speed`函数来设置风扇的速度。你需要根据实际情况实现这个函数，以便控制风扇的速度。

这只是一个简单的示例，你可以根据自己的需要对其进行修改和扩展。*/