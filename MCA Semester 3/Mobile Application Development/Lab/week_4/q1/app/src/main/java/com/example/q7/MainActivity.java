package com.example.q7;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.ToggleButton;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    EditText name;
    RadioGroup rg;
    RadioButton male;
    RadioButton female;
    CheckBox sports;CheckBox art;CheckBox sw;
    ToggleButton toggleButton;
    TextView eyd;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        name = (EditText) findViewById(R.id.editTextText1);
        rg = (RadioGroup) findViewById(R.id.rg);
        male = (RadioButton) findViewById(R.id.rb1);
        female = (RadioButton) findViewById(R.id.rb2);
        sports = (CheckBox) findViewById(R.id.sports);
        art = (CheckBox) findViewById(R.id.art);
        sw = (CheckBox) findViewById(R.id.sw);
        toggleButton = findViewById(R.id.toggleButton);
        eyd = ( TextView) findViewById(R.id.eyd);

    }
    public void onButtonClick(View view) {
        if (toggleButton.isChecked()) {
            String userName = name.getText().toString().trim();
            String selectedGender = null;
            String selectedLikes = "";

            // Validation for the name field
            if (userName.isEmpty()) {
                Toast.makeText(MainActivity.this, "Name field cannot be empty", Toast.LENGTH_SHORT).show();
                return;
            }

            // Get selected gender
            int selectedGenderId = rg.getCheckedRadioButtonId();
            if (selectedGenderId == R.id.rb1) {
                selectedGender = "male";
            } else if (selectedGenderId == R.id.rb2) {
                selectedGender = "female";
            } else {
                Toast.makeText(MainActivity.this, "Please select a gender", Toast.LENGTH_SHORT).show();
                return;
            }

            // Get selected likes
            if (sports.isChecked()) {
                selectedLikes += "sports, ";
            }
            if (art.isChecked()) {
                selectedLikes += "art, ";
            }
            if (sw.isChecked()) {
                selectedLikes += "social work, ";
            }

            // Remove the trailing comma and space, if any
            if (!selectedLikes.isEmpty()) {
                selectedLikes = selectedLikes.substring(0, selectedLikes.length() - 2);
            } else {
                selectedLikes = "nothing!";
            }

            // Update the TextViews
            eyd.setText("Hello " + userName);
            Intent resPage = new Intent(MainActivity.this, ResultActivity.class);
            String[] msg = {userName, selectedLikes, selectedGender};
            resPage.putExtra("Text", msg);
            startActivity(resPage);
            InputMethodManager imm = (InputMethodManager) getSystemService(Context.INPUT_METHOD_SERVICE);
            imm.hideSoftInputFromWindow(view.getWindowToken(), 0);

        } else {
            onResetClick(view);
        }
    }
    public void onResetClick(View view) {
        // Reset all fields
        name.setText("");
        rg.clearCheck();
        sports.setChecked(false);
        art.setChecked(false);
        sw.setChecked(false);
        eyd.setText("Enter Your Details");
        toggleButton.setChecked(false);

    }
}