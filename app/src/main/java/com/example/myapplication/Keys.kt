package com.example.myapplication



object Keys {

    init {
        System.loadLibrary("native-lib")
    }

    external fun apiKey(): String
    external fun apiKeys(): String
}