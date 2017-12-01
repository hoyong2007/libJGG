.class Ljgg/dummy/MainActivity$1;
.super Ljava/lang/Object;
.source "MainActivity.java"

# interfaces
.implements Landroid/view/View$OnClickListener;


# annotations
.annotation system Ldalvik/annotation/EnclosingMethod;
    value = Ljgg/dummy/MainActivity;->onCreate(Landroid/os/Bundle;)V
.end annotation

.annotation system Ldalvik/annotation/InnerClass;
    accessFlags = 0x0
    name = null
.end annotation


# instance fields
.field final synthetic this$0:Ljgg/dummy/MainActivity;


# direct methods
.method constructor <init>(Ljgg/dummy/MainActivity;)V
    .locals 0
    .param p1, "this$0"    # Ljgg/dummy/MainActivity;

    .prologue
    .line 19
    iput-object p1, p0, Ljgg/dummy/MainActivity$1;->this$0:Ljgg/dummy/MainActivity;

    invoke-direct {p0}, Ljava/lang/Object;-><init>()V

    return-void
.end method


# virtual methods
.method public onClick(Landroid/view/View;)V
    .locals 1
    .param p1, "view"    # Landroid/view/View;

    .prologue
    .line 22
    const-string v0, "JGG"

    invoke-static {v0}, Ljava/lang/System;->loadLibrary(Ljava/lang/String;)V

    .line 23
    return-void
.end method
