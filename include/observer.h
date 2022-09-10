#ifndef OBSERVER_H
#define OBSERVER_H
#define observer_struct_name(event_struct) event_struct ## Observers

#define def_observers(event_struct) typedef struct { \
    unsigned short num_observers; \
    void (** observers) ( event_struct * event); \
    } observer_struct_name(event_struct) 

#define def_obs_invoke(event_struct, event_name) \
   void on_## event_name( event_struct * event, observer_struct_name(event_struct) * observers) \
   { \
     for(int i = 0; i < observers->num_observers; i++) observers->observers[i](event); \
   }

#define GENERATE_OBSERVERS(event_struct, event_name) \
    def_observers(event_struct); \
    def_obs_invoke(event_struct, event_name)
#endif