#include <Novice.h>
#include "Player.h"
#include "Enemy.h"

const char kWindowTitle[] = "LC1B_05_オザワ_ユウト_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Player *player = new Player();
	Enemy* enemy[2] = {
		new Enemy(640,200),
		new Enemy(300,300) 
	};

	Vector2 range;
	float radius;
	float distance;

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		player->Update(keys);
		enemy[0]->Update();
		enemy[1]->Update();


		if (!player->GetBullet().empty()) {
			size_t temp = player->GetBullet().size();
			for (int i = 0; i < temp; i++) {
				for (int j = 0; j < 2; j++) {
					range = (player->GetBullet()[i]->GetPos()) - enemy[j]->GetPos();
					distance = (range.x * range.x) + (range.y * range.y);
					radius = (player->GetBullet()[i]->GetRadius()) + (enemy[j]->GetRadius());
					if (distance <= radius * radius) {
						enemy[j]->isAlive = false;
					}
				}
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		player->Draw();
		enemy[0]->Draw();
		enemy[1]->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete player;
	delete enemy[0];
	delete enemy[1];

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
