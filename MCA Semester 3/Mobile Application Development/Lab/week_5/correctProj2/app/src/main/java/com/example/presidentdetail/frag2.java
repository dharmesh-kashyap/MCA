package com.example.presidentdetail;

import android.os.Bundle;
import androidx.fragment.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

public class frag2 extends Fragment {
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_frag2, container, false);

        TextView nameTextView = view.findViewById(R.id.presidentName);
        ImageView imageView = view.findViewById(R.id.presidentImage);

        Bundle bundle = getArguments();
        if (bundle != null) {
            String presidentName = bundle.getString("president_name");
            nameTextView.setText(presidentName);

            int imageResId = getImageResource(presidentName);
            imageView.setImageResource(imageResId);
        }

        return view;
    }

    private int getImageResource(String presidentName) {
        int imageResId;
        if (presidentName.equals("Dr. Rajendra Prasad")) {
            imageResId = R.drawable.rajendra_prasad;
        } else if (presidentName.equals("Dr. Sarvepalli Radhakrishnan")) {
            imageResId = R.drawable.sarvepalli_radhakrishnan;
        } else if (presidentName.equals("Dr. Zakir Husain")) {
            imageResId = R.drawable.zakir_husain;
        } else if (presidentName.equals("Varahagiri Venkata Giri")) {
            imageResId = R.drawable.vv_giri;
        } else if (presidentName.equals("Fakhruddin Ali Ahmed")) {
            imageResId = R.drawable.fakhruddin_ali_ahmed;
        } else if (presidentName.equals("Giani Zail Singh")) {
            imageResId = R.drawable.giani_zail_singh;
        } else if (presidentName.equals("Dr. Shankar Dayal Sharma")) {
            imageResId = R.drawable.shankar_dayal_sharma;
        } else if (presidentName.equals("Dr. K. R. Narayanan")) {
            imageResId = R.drawable.kr_narayanan;
        } else if (presidentName.equals("Dr. A. P. J. Abdul Kalam")) {
            imageResId = R.drawable.apj_abdul_kalam;
        } else if (presidentName.equals("Pratibha Patil")) {
            imageResId = R.drawable.pratibha_patil;
        } else if (presidentName.equals("Pranab Mukherjee")) {
            imageResId = R.drawable.pranab_mukherjee;
        } else if (presidentName.equals("Ram Nath Kovind")) {
            imageResId = R.drawable.ram_nath_kovind;
        } else if (presidentName.equals("Droupadi Murmu")) {
            imageResId = R.drawable.droupadi_murmu;
        } else {
            imageResId = R.drawable.default_image;
        }
        return imageResId;
    }
}
