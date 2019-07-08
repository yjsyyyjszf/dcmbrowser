#include "ui.h"

void InitializeImGui(GLFWwindow *window, const char *glsl_version)
{
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Read 'misc/fonts/README.txt' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != NULL);
}

void RenderImGui(GLFWwindow *window, UIState state)
{
    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    if (state.no_titlebar)        state.window_flags |= ImGuiWindowFlags_NoTitleBar;
    if (state.no_scrollbar)       state.window_flags |= ImGuiWindowFlags_NoScrollbar;
    if (!state.no_menu)           state.window_flags |= ImGuiWindowFlags_MenuBar;
    if (state.no_move)            state.window_flags |= ImGuiWindowFlags_NoMove;
    if (state.no_resize)          state.window_flags |= ImGuiWindowFlags_NoResize;
    if (state.no_collapse)        state.window_flags |= ImGuiWindowFlags_NoCollapse;
    if (state.no_nav)             state.window_flags |= ImGuiWindowFlags_NoNav;
    if (state.no_background)      state.window_flags |= ImGuiWindowFlags_NoBackground;
    if (state.no_bring_to_front)  state.window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus;
    if (state.no_close)           state.open = NULL; // Don't pass our bool* to Begin

    // Main UI Interface
    ImGui::SetNextWindowPos(ImVec2(0, 20));
    if(ImGui::Begin("dcmbrowser", &state.open, state.window_flags))
    {
        // Menu Bar
        if (ImGui::BeginMainMenuBar())
        {  
            if(ImGui::BeginMenu("File"))
            {
                if(ImGui::MenuItem("Open")) {}
                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }
        
        // File Browsing
        ImGui::Text("Folder Input Text Widget Will Go Here");
        ImGui::SameLine();
        if(ImGui::Button("...")) {} // Browse Code Here
        ImGui::SameLine(); 
        if (ImGui::Button("Scan")) {} // Scan Code Here)

        // File Display (Left)

        // File Properties (Right)

        // File Manipulation Options
        
    }
    ImGui::End();
    
    if (state.show_demo_window)
        ImGui::ShowDemoWindow(&state.show_demo_window);

    // Rendering
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(state.clear_color.x, state.clear_color.y, state.clear_color.z, state.clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void CleanupImGui()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}