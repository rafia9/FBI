#include <stdio.h>

#include <3ds.h>

#include "action.h"
#include "../task/task.h"
#include "../../error.h"
#include "../../list.h"
#include "../../ui.h"
#include "../../../core/linkedlist.h"

static void action_install_titledb_draw_top(ui_view* view, void* data, float x1, float y1, float x2, float y2, u32 index) {
    ui_draw_titledb_info(view, ((list_item*) data)->data, x1, y1, x2, y2);
}

void action_install_titledb(linked_list* items, list_item* selected) {
    char url[64];
    snprintf(url, INSTALL_URL_MAX, "https://3ds.titledb.com/v1/cia/%lu/download", ((titledb_info*) selected->data)->id);

    action_url_install("Install the selected title from TitleDB?", url, selected, NULL, action_install_titledb_draw_top);
}