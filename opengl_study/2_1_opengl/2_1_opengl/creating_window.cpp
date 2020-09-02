//
//  main.cpp
//  2_1_opengl
//
//  Created by kawaii on 2020/08/25.
//  Copyright © 2020 kawaii. All rights reserved.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

//윈도우 창의 높이 넓이
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    glfwInit();  //glwf초기화
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //맥os에서는 추가해줘야함
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

   //원도우 객체 생성
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    //glad opengl용 함수포인터
    //glfwGetProcAddress 컴파일 할 환경의 os
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //render loop 이미지를 그리고 바로 꺼지는 것을 막기위해서 loop를 돌려줘야함
    //glfwWindowShouldClose :응용프로그램을 닫았는지
    //glfwPollEvents : 이벤트가 발생했는지 확인 , 윈도우 상태 업데이트 , 콜백함수 호출
    //glfwSwapBuffers : 컬러버퍼를 교체
    //----------------------------------------------------------------
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //할당한 자원 정리
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window)
{
    //키보드 키 입력 받기 ,,esc 버튼 눌렸는지 확인 
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

//창의 크기가 변경될때 마다 적절한 데이터 채우기
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
