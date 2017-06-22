#include <stdio.h>
#include <string.h>

struct gps_t
{
    double lon;
    double lat;
};

int gps_parse_line( struct gps_t *gps, const char *buffer )
{
    if( 2 != sscanf(buffer,"$GPRMC,%*f,A,%lf,N,%lf",&gps->lat,&gps->lon) )
        return 1; // Ê§°Ü
    return 0; // ³É¹¦
}

int main(int argc, char *argv[])
{
    struct gps_t gps;
    const char *buffer = "$GPRMC,013946.00,A,3202.1855,N,11849.0769,E,0.05,218.30,111105,4.5,W,A*20";
    if( 0 == gps_parse_line(&gps,buffer) )
        printf( "lon: %.4f, lat: %.4f\n", gps.lon, gps.lat );

    return 0;
}
