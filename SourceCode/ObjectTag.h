#pragma once
#include<vector>

/*��ޕʃ^�O�N���X*/
enum class ObjectTag:unsigned char
{
    Player,     //�v���C���[
    Archer,     //�A�[�`���[
    Enemy,      //�G�l�~�[
};

/*���[�v����p*/
constexpr static ObjectTag ObjTagAll[] =
{
    ObjectTag::Player,
    ObjectTag::Archer,
    ObjectTag::Enemy,
};

