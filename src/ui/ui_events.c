#include "ui.h"
#include "lvgl.h"
#include <rtthread.h>
#include <stdio.h>

int current_score = 0;
static int elapsed_seconds = 0;

static lv_timer_t * game_timer = NULL;

static void game_timer_callback(lv_timer_t * timer)
{
    (void)timer;

    elapsed_seconds++;

    int minutes = elapsed_seconds / 60;
    int seconds = elapsed_seconds % 60;

    if (ui_LabelTimer1 != NULL) {
        lv_label_set_text_fmt(ui_LabelTimer1, "%02d:%02d", minutes, seconds);
    }
}

void IncrementScore(lv_event_t * e)
{
    (void)e;
    current_score++;
    rt_kprintf("Correct! Score: %d\n", current_score);
}

void UpdateScoreLabel(lv_event_t * e)
{
    (void)e;
    rt_kprintf("Updating Score Label. Final Score: %d\n", current_score);

    if (ui_LabelScore != NULL) {
        lv_label_set_text_fmt(ui_LabelScore, "%d", current_score);
    }
}

void StartGameTrigger(lv_event_t * e)
{
    (void)e;

    elapsed_seconds = 0;
    current_score = 0;

    if (ui_LabelTimer1 != NULL) {
        lv_label_set_text(ui_LabelTimer1, "00:00");
    }

    if (game_timer == NULL) {
        game_timer = lv_timer_create(game_timer_callback, 1000, NULL);
    } else {
        lv_timer_resume(game_timer);
    }

    rt_kprintf("Game Timer Started.\n");
}

void StopGameTrigger(lv_event_t * e)
{
    (void)e;

    if (game_timer != NULL) {
        lv_timer_pause(game_timer);
    }

    int minutes = elapsed_seconds / 60;
    int seconds = elapsed_seconds % 60;

    printf("Game Finished! Total Time: %02d:%02d. Final Score: %d\n",
           minutes, seconds, current_score);
}
