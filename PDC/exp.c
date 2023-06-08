#include <stdio.h>
#include <math.h>
#include <omp.h>
struct point
{
    double x;
    double y;
    int cluster;
};
double distance(struct point p1, struct point p2)
{
    double ans;
    ans = sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
    return ans;
}
int main()
{
    int np = 0, nc = 0;
    printf("Enter the number of points\n");
    scanf("%d", &np);
    printf("Enter the number of clusters\n");
    scanf("%d", &nc);
    int l, k;
    struct point points[np];
    struct point clusters[nc];
    for (l = 0; l < np; l++)
    {
        printf("Enter the x - co-ordinate of point %d\n", l + 1);
        scanf("%lf", &points[l].x);
        printf("Enter the y - co-ordinate of point %d\n", l + 1);
        scanf("%lf", &points[l].y);
    }
    for (l = 0; l < nc; l++)
    {
        printf("Enter the x - co-ordinate of initial mean of cluster %d\n", l + 1);
        scanf("%lf", &clusters[l].x);
        printf("Enter the y - co-ordinate of initial mean of cluster %d\n", l + 1);
        scanf("%lf", &clusters[l].y);
        clusters[l].cluster = l + 1;
    }
    printf("The number of processors are:%d\n", omp_get_num_procs());
    printf("The number of threads are:%d\n", omp_get_max_threads());
    double time = omp_get_wtime();
    int i = 0, j = 0;
#pragma omp for
    for (k = 0; k < 10; k++)
    {
        for (i = 0; i < np; i++)
        {
            double min = 9999.99;
            int min_cluster;
            for (j = 0; j < nc; j++)
            {
                if (distance(points[i], clusters[j]) < min)
                {
                    min = distance(points[i], clusters[j]);
                    min_cluster = clusters[j].cluster;
                }
            }
            points[i].cluster = min_cluster;
        }
        int flagg = 0;
        for (i = 1; i <= nc; i++)
        {
            double Mx = 0.0;
            double My = 0.0;
            int
                counter = 0;
            for (j = 0; j < np; j++)
            {
                if (points[j].cluster == i)
                {
                    Mx = Mx + points[j].x;
                    My = My + points[j].y;
                    counter++;
                }
            }
            Mx = Mx / counter;
            My = My / counter;
            if (clusters[i - 1].x != Mx || clusters[i - 1].y != My)
            {
                flagg = 1;
            }
            clusters[i - 1].x = Mx;
            clusters[i - 1].y = My;
        }
        printf("\n\nIteration %d\n\n\n", k + 1);
        for (i = 0; i < nc; i++)
        {
            printf("Cluster %d ", i + 1);
            for (j = 0; j < np; j++)
            {
                if (points[j].cluster == i + 1)
                {
                    printf(",(%f,%f)", points[j].x, points[j].y);
                }
            }
            printf(".\n Mean = (%f,%f).\n\n\n", clusters[i].x, clusters[i].y);
        }
        time = omp_get_wtime() - time;
        printf("The parallel execution time is %lf", time);
    }
    return 0;
