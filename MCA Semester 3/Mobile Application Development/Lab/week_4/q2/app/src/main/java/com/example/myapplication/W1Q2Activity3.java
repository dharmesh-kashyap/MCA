package com.example.myapplication;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class W1Q2Activity3 extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_w1_q23);
        Toast.makeText(this, "App has started", Toast.LENGTH_SHORT).show();
    }

    // Method to be called when the button is clicked
    public void showToast(View view) {
        Toast.makeText(this, "Button has been clicked", Toast.LENGTH_SHORT).show();
    }
    public void backToHome(View view) {
        // Replace with the package and main activity of your home app
        Intent intent = new Intent(W1Q2Activity3.this, MainActivity.class);
        startActivity(intent);
    }
}