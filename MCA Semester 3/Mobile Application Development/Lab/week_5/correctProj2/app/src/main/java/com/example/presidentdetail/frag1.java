package com.example.presidentdetail;

import android.os.Bundle;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import java.util.ArrayList;

public class frag1 extends Fragment {
    View view;
    ListView lv;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        view = inflater.inflate(R.layout.fragment_frag1, container, false);
        lv = view.findViewById(R.id.listView);

        ArrayList<String> presidents = new ArrayList<>();
        presidents.add("Dr. Rajendra Prasad");
        presidents.add("Dr. Sarvepalli Radhakrishnan");
        presidents.add("Dr. Zakir Husain");
        presidents.add("Varahagiri Venkata Giri");
        presidents.add("Fakhruddin Ali Ahmed");
        presidents.add("Giani Zail Singh");
        presidents.add("Dr. Shankar Dayal Sharma");
        presidents.add("Dr. K. R. Narayanan");
        presidents.add("Dr. A. P. J. Abdul Kalam");
        presidents.add("Pratibha Patil");
        presidents.add("Pranab Mukherjee");
        presidents.add("Ram Nath Kovind");
        presidents.add("Droupadi Murmu");

        ArrayAdapter<String> arrayAdapter = new ArrayAdapter<>(requireContext(), android.R.layout.simple_list_item_1, presidents);
        lv.setAdapter(arrayAdapter);

        lv.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                String selectedPresident = presidents.get(position);
                Bundle bundle = new Bundle();
                bundle.putString("president_name", selectedPresident);

                Fragment detailsFragment = new frag2();
                detailsFragment.setArguments(bundle);

                FragmentManager fragmentManager = getParentFragmentManager();
                FragmentTransaction transaction = fragmentManager.beginTransaction();

                // Change: Replacing the correct FrameLayout id in PresidentActivity instead of listView
                transaction.replace(R.id.frameLayout, detailsFragment);

                transaction.addToBackStack(null);
                transaction.commit();
            }
        });

        return view;
    }
}
