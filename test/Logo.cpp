#include "Logo.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "Player.h"
#include "Enemy.h"

#include "ObjectFactory.h"

Logo::Logo() { }
Logo::~Logo() { }

void Logo::Initialize()
{
	ObjectManager::GetInstance()->AddObject(ObjectFactory<Player>::CreateObject());
}

void Logo::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_ENTER)
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);
}

void Logo::Render()
{
	CursorManager::GetInstance()->WriteBuffer(15.0f, 6.0f, (char*)"    {__   {__     {__{__ {__   {________     {_______    {__     {__  {__ __  {__     {__");
	CursorManager::GetInstance()->WriteBuffer(15.0f, 7.0f, (char*)" {__   {__{__     {__{_    {__ {__           {__    {__  {__     {__{__    {__{__     {__");
	CursorManager::GetInstance()->WriteBuffer(15.0f, 8.0f, (char*)"{__       {__     {__{_     {__{__           {__    {__  {__     {__ {__      {__     {__");
	CursorManager::GetInstance()->WriteBuffer(15.0f, 9.0f, (char*)"{__       {__     {__{___ {_   {______       {_ {__      {__     {__   {__    {______ {__");
	CursorManager::GetInstance()->WriteBuffer(15.0f, 10.0f, (char*)"{__       {__     {__{_     {__{__           {__  {__    {__     {__      {__ {__     {__");
	CursorManager::GetInstance()->WriteBuffer(15.0f, 11.0f, (char*)" {__   {__{__     {__{_      {_{__           {__    {__  {__     {__{__    {__{__     {__");
	CursorManager::GetInstance()->WriteBuffer(15.0f, 12.0f, (char*)"   {____    {_____   {____ {__ {________     {__      {__  {_____     {__ __  {__     {__");
}

void Logo::Release()
{
}