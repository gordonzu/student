return 

int my_count = std::all_of(count_set.begin(),count_set.end(),
           [](const std::pair<double,int> p) { 
              return p.second == 0;
           }
);

}
