#pragma once
// -- Core -------------------------------------
#include "Glitch/Core/Application.h"
#include "Glitch/Core/Object.h"
#include "Glitch/Core/ErrorCodes.h"
#include "Glitch/Log/Log.h"
#include "Glitch/Events/Event.h"
// ---------------------------------------------
// -- SceneManager -----------------------------
#include "Glitch/Renderer/SceneManager/SceneManager.h"
#include "Glitch/Renderer/SceneManager/Scene.h"
// ---------------------------------------------
// -- SoundEngine ------------------------------
#include "Glitch/Sound/SoundEngine.h"
// ---------------------------------------------
// -- EntryPoint -------------------------------
#include "Glitch/EntryPoint.h"
// ---------------------------------------------

// TODO Physics implementeren
// TODO Sound overzetten
// TODO add things to export here
// TODO Alles nalopen
// TODO netcode onderzoeken van tlc
// TODO Renderer apart zetten van window
// TODO input afhandeling uit window halen

// TODO vsync 30/60 trekt de engine verder naar beneden als hij slecht preformed omdat dit geen rekening houdt 
// met de executietijden binnen de engine (delta time)
// https://gamedev.net/forums/topic/685960-the-39perfect39-game-loop-fix-your-time-step-by-step/5330446/
// limiting op basis van static constanten is a big nono 
// https://www.gamedev.net/forums/topic/665939-how-to-limit-your-fps/