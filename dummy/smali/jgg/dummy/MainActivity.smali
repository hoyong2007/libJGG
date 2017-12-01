.class public Ljgg/dummy/MainActivity;
.super Landroid/support/v7/app/AppCompatActivity;
.source "MainActivity.java"


# instance fields
.field btn:Landroid/widget/Button;


# direct methods
.method public constructor <init>()V
    .locals 0

    .prologue
    .line 8
    invoke-direct {p0}, Landroid/support/v7/app/AppCompatActivity;-><init>()V

    return-void
.end method


# virtual methods
.method protected onCreate(Landroid/os/Bundle;)V
    .locals 2
    .param p1, "savedInstanceState"    # Landroid/os/Bundle;

    .prologue
    .line 14
    invoke-super {p0, p1}, Landroid/support/v7/app/AppCompatActivity;->onCreate(Landroid/os/Bundle;)V

    .line 15
    const v0, 0x7f04001b

    invoke-virtual {p0, v0}, Ljgg/dummy/MainActivity;->setContentView(I)V

    .line 17
    const v0, 0x7f0b005e

    invoke-virtual {p0, v0}, Ljgg/dummy/MainActivity;->findViewById(I)Landroid/view/View;

    move-result-object v0

    check-cast v0, Landroid/widget/Button;

    iput-object v0, p0, Ljgg/dummy/MainActivity;->btn:Landroid/widget/Button;

    .line 19
    iget-object v0, p0, Ljgg/dummy/MainActivity;->btn:Landroid/widget/Button;

    new-instance v1, Ljgg/dummy/MainActivity$1;

    invoke-direct {v1, p0}, Ljgg/dummy/MainActivity$1;-><init>(Ljgg/dummy/MainActivity;)V

    invoke-virtual {v0, v1}, Landroid/widget/Button;->setOnClickListener(Landroid/view/View$OnClickListener;)V

    .line 25
    return-void
.end method
