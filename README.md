# Securing-Api-NDK

1.	Download Android Studio
   https://developer.android.com/studio/index.html

Click “Download Android Studio”, accept the terms and conditions, and proceed with the download.
The download might take a while, as it is about 700 MB. Run the installer after the download is finished.
2.	Install Android Studio
When running the installer, we recommend using the default values, as shown below. Once installed, Android Studio will run, and launch a setup wizard to download additional components.




3.	Run Android Studio Setup Wizard
When you first start Android Studio, it will offer to import any previous settings. Since this is likely your first installation, there are no settings to import. Again, just accept the default option and continue.

 
Next, select the UI theme. Choose whichever one you prefer -- this is simply a matter of preference. On the next screen, select the option to install an Android Virtual Device. You will need an actual Android device for this course, but this virtual device can be useful.


Accept the recommended RAM size for the emulator, and click “Next” to see a summary of the components to be downloaded. The additional components total about 1.8 GB in size.


When the download begins, the progress bar might appear to freeze, but do not worry -- the download is progressing. Once installation is complete, click “Finish”.

 
4.	Begin Developing
The Create New Project appears. The first option is to select the type of activity. Choose Empty, which is the default and click Next.
 

Configure your project is the next screen. It will ask for the name of the Application, Package Name, Project path, language, and API Level. Keep the defaults and click on Finish

 	 

Wait for it to finish. Once everything is downloaded and installed, the new project is created and you are taken to the Android workspace.
Create New Virtual Device
If you are starting the AVD Manager for the first time, you will see the following screen.  Else you will see the list of AVDs created.

 	 

In the left-hand panel displays a list of the Category of the device.  It includes TV, Phone, Wear & Tablet. Select the category.
The middle pane displays the list of devices available. Select one based on the requirement of your app. After this click on the Next button.
Note that phones with larger resolution Choose the pixels resolution according to your requirements as it will take huge RAM in large pixels resolution device. If your computer has low RAM, then prefer to choose less resolution device. Click Next to continue
 	 
Choose the system image based on the API level targeted by your App. The app won’t run if you choose lower API than the one target by the App,Select the image and click on Next to continue.
Here you can name your AVD, change startup orientation and few other hardware properties. Click on Show Advanced Settings to show more settings.
Click on Finish to create the AVD.
 
Under the action column, click on the   icon to run the AVD. The Android Emulator uses the AVD to mimic the device.  You can then use the control panel to manage the device. The Extend control button at the bottom gives you more options
Securing API Keys in Android App using NDK
Step 1: Install the required tools
•	NDK (Native Development Kit)
•	LLDB (Low Level Debugger)
•	CMake
Step 2: Create a (native-lib.cpp) file
Create a new folder, cpp, inside app/src/main.
Once you've created it, right-click on the cpp folder, click on New → C/C++ Source File, and name your file native-lib.
Step 3: Store your API key inside the native-lib.cpp file
Inside your native-lib.cpp, add the following code:
Multiple securing api keys
#include <jni.h>
#include <string>
extern "C" JNIEXPORT jstring
JNICALL
Java_com_package_name_Keys_apiKey1(JNIEnv *env, jobject object) {
std::string api_key1= "your_api_key_goes_here";
Java_com_package_name_Keys_apiKey2(JNIEnv *env, jobject object) {
std::string api_key2= "your_api_key_goes_here";
return env->NewStringUTF(api_key2.c_str());}

Step 4: Create a CMakeLists.txt file
Under the app/ folder, create a new text file and name it CMakeLists.txt. Add the following code in the file:

# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html
# Sets the minimum version of CMake required to build the native library.
cmake_minimum_required(VERSION 3.4.1)
# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
add_library( # Sets the name of the library.
             native-lib
          # Sets the library as a shared library.
             SHARED
             # Provides a relative path to your source file(s).
             src/main/cpp/native-lib.cpp )
# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.
find_library( # Sets the name of the path variable.
              log-lib
            # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.
target_link_libraries( # Specifies the target library.
                       native-lib
                     # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )

Step 5: Configure Gradle for CMake
Add the following lines to the android block in your app-level build.gradle file:
android {
externalNativeBuild {
cmake {
path "CMakeLists.txt"
    }
  }
}

Step 6: Creating the Keys.kt file
Create a Kotlin object, Keys.kt, and obtain your API key as followed:
object Keys {
init {
System.loadLibrary("native-lib")
    }
    external fun apiKey1(): String
  external fun apiKey2(): String

}
Once you've done this, you can then get a reference to your method by declaring an external Kotlin function under the same name as the one mentioned above in Step 3. In this example, it's apiKey().
Now, to get your API key from any part of your app, just call:
                      Keys.apiKey1()
                      Keys.apiKey2()







