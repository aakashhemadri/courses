#ifndef CONFIG_H
#define CONFIG_H

//Set type of factory
#define SIMPLE

#define prnt_str(X) for(auto i : X) std::cout<<" ";
#define ret_len(X) for(int count = 0; X /= 10 ; count++); count

#endif // CONFIG_H
