cmake_minimum_required(VERSION 3.14.0)
set(CMAKE_OSX_DEPLOYMENT_TARGET 10.13 CACHE STRING "")

set(vst3sdk_SOURCE_DIR "C:/include/VST_SDK/vst3sdk")
if(NOT vst3sdk_SOURCE_DIR)
    message(FATAL_ERROR "Path to VST3 SDK is empty!")
endif()

project(learnVST3
    # This is your plug-in version number. Change it here only.
    # Version number symbols usable in C++ can be found in
    # source/version.h and ${PROJECT_BINARY_DIR}/projectversion.h.
    VERSION 1.0.0.0 
    DESCRIPTION "learnVST3 VST 3 Plug-in"
)

set(SMTG_VSTGUI_ROOT "${vst3sdk_SOURCE_DIR}")

add_subdirectory(${vst3sdk_SOURCE_DIR} ${PROJECT_BINARY_DIR}/vst3sdk)
smtg_enable_vst3_sdk()

smtg_add_vst3plugin(learnVST3
    source/version.h
    source/pl_cids.h
    source/pl_processor.h
    source/pl_processor.cpp
    source/pl_controller.h
    source/pl_controller.cpp
    source/pl_entry.cpp
)

#- VSTGUI Wanted ----
if(SMTG_ADD_VSTGUI)
    target_sources(learnVST3
        PRIVATE
            resource/pl_editor.uidesc
    )
    target_link_libraries(learnVST3
        PRIVATE
            vstgui_support
    )
    smtg_target_add_plugin_resources(learnVST3
        RESOURCES
            "resource/pl_editor.uidesc"
    )
endif(SMTG_ADD_VSTGUI)
# -------------------

smtg_target_add_plugin_snapshots (learnVST3
    RESOURCES
        resource/CA217282F4315EE3943633B467AF7A92_snapshot.png
        resource/CA217282F4315EE3943633B467AF7A92_snapshot_2.0x.png
)

target_link_libraries(learnVST3
    PRIVATE
        sdk
)

smtg_target_configure_version_file(learnVST3)

if(SMTG_MAC)
    smtg_target_set_bundle(learnVST3
        BUNDLE_IDENTIFIER net.nws.learnvst3
        COMPANY_NAME "My Plug-in Company"
    )
    smtg_target_set_debug_executable(learnVST3
        "/Applications/VST3PluginTestHost.app"
        "--pluginfolder;$(BUILT_PRODUCTS_DIR)"
    )
elseif(SMTG_WIN)
    target_sources(learnVST3 PRIVATE 
        resource/win32resource.rc
    )
    if(MSVC)
        set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT learnVST3)

        smtg_target_set_debug_executable(learnVST3
            "$(ProgramW6432)/Steinberg/VST3PluginTestHost/VST3PluginTestHost.exe"
            "--pluginfolder \"$(OutDir)/\""
        )
    endif()
endif(SMTG_MAC)
