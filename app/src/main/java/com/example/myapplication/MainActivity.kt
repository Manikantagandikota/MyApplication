package com.example.myapplication

import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val tvKey = findViewById<TextView>(R.id.tvKey) as TextView
        val tvKey1 = findViewById<TextView>(R.id.tvKey1) as TextView
        tvKey.text =  Keys.apiKey();
        tvKey1.text =  Keys.apiKeys()


    }
}