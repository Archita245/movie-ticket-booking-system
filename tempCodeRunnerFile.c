#include <stdio.h>
#include <string.h>

#define MAX_SEATS 30 

typedef struct {
    int movie_id;
    char movie_name[50];
    char timing[10];
    int seats[MAX_SEATS]; 
} Movie;

Movie movies[] = {
    {1, "Harry Potter Part 8", "10:00 AM", {0}},
    {2, "Srikanth", "1:00 PM", {0}},
    {3, "Kal Ho Na Ho", "6:00 PM", {0}},
    {4, "Annabelle 2", "9:00 PM", {0}}
};

void display_movies() {
    printf("\nAvailable Movies:\n");
    for (int i = 0; i < 4; i++) {
        printf("ID: %d | %s | %s\n", movies[i].movie_id, movies[i].movie_name, movies[i].timing);
    }
}

int select_movie() {
    int choice;
    printf("\nEnter Movie ID to book a ticket: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > 4) {
        printf("Invalid choice. Please try again.\n");
        return select_movie();
    }
    return choice - 1; 
}

void display_seats(int movie_index) {
    printf("\nSeating Arrangement for %s (%s):\n", movies[movie_index].movie_name, movies[movie_index].timing);
    for (int i = 0; i < MAX_SEATS; i++) {
        if (movies[movie_index].seats[i] == 0) {
            printf("[Seat %d - Vacant] ", i + 1);
        } else {
            printf("[Seat %d - Booked] ", i + 1);
        }
        if ((i + 1) % (i+1) == 0) { 
            printf("\n");
        }
    }
}

void book_ticket(int movie_index) {
    int seat_number;
    display_seats(movie_index);
    printf("\nEnter the seat number you want to book (1-%d): ", MAX_SEATS);
    scanf("%d", &seat_number);
    if (seat_number < 1 || seat_number > MAX_SEATS || movies[movie_index].seats[seat_number - 1] == 1) {
        printf("Invalid or already booked seat. Please choose another.\n");
        book_ticket(movie_index);
        return;
    }
    movies[movie_index].seats[seat_number - 1] = 1;
    printf("\nBooking successful!\n");
    printf("Movie: %s\nTiming: %s\nSeat Number: %d\n", movies[movie_index].movie_name, movies[movie_index].timing, seat_number);
    printf("\nUpdated Seating Arrangement:\n");
    display_seats(movie_index);
}

int main() {
    char choice;
    do {
        display_movies();
        int movie_index = select_movie();
        do {
            book_ticket(movie_index);
            printf("\nWould you like to book another ticket for the same movie? (y/n): ");
            scanf(" %c", &choice);
        } while (choice == 'y' || choice == 'Y');
        printf("\nWould you like to book a ticket for a different movie? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    printf("\nThank you for using the Movie Ticket Booking System!\n");
    return 0;
}