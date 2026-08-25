*** UID:0000D5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000N9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ShoutInputPane : public LineInputPane
{
public:
    ShoutInputPane();

protected:
    virtual void OnSubmitInput();
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

## UID0000N9 Whole-File Topology Synchronization - 2026-08-25

- Score is `93/94` after exact raw constructor, submit virtual, `L"! "` prompt, opcode `0x0e` subtype `1`, vtable, header, and source-route closure. Deterministic emitter position is `70`.
- Formal CPP is `[[CHILDREN]]`; formal H owns the complete class declaration without an explicit destructor. UID0002SA and UID0001MF remain the exact constructor and submit children.

# ShoutInputPane

## Status

- Confidence: strong for confirmed behavior, constructor boundary, vtable slots, and `SayInputPanes` ownership.
- Likely source file: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- Address range: raw constructor [UID:0002SA][0x005b4220-0x005b4255.ShoutInputPaneRawConstructor](by-memory/0x005b4220-0x005b4255.ShoutInputPaneRawConstructor.md), submit body [UID:0001MF][0x005b4260-0x005b43bc.ShoutInputPane](by-memory/0x005b4260-0x005b43bc.ShoutInputPane.md), plus helper at [UID:0001KO][0x005a4b60-0x005a5791.SayModeHelpers](by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md)
- Historical generated/recovered file: `source-3/simroot_v2/class_ShoutInputPane.cpp`; current source placement is shared `NexusTK/social/SayInputPanes.cpp/.h`.

## Class Purpose

`ShoutInputPane` is the shout chat input pane. It uses the shout prefix prompt, trims and normalizes text, and sends opcode `0x0e`, subtype `1`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `CreateShoutInputPane` | `0x005a5710-0x005a5791` | Allocates and initializes a shout input pane from the mode-opening flow. |
| `ShoutInputPane` | [UID:0002SA][0x005b4220-0x005b4255.ShoutInputPaneRawConstructor](by-memory/0x005b4220-0x005b4255.ShoutInputPaneRawConstructor.md) | Raw constructor-shaped body; current 2026-06-25 MCP evidence confirms no IDA function object or direct raw-start route, but the child is now first-draft populated as a `LineInputPane` base initializer with the `L"! "` prompt. |
| shout prompt literal | [UID:0003JS][0x00630a6c-0x00630a78.ShoutPromptString](by-memory/0x00630a6c-0x00630a78.ShoutPromptString.md) | Source-declared `L"! "` prompt used by the creator and raw constructor. |
| `OnSubmitInput` | [UID:0001MF][0x005b4260-0x005b43bc.ShoutInputPane](by-memory/0x005b4260-0x005b43bc.ShoutInputPane.md) | First-draft populated exact virtual submit child; sends opcode `0x0e`, subtype `1` shout chat packet through `g_packetSender`. |

## Evidence Notes

- Current IDA MCP session `80de0a67` on 2026-06-25 reconfirmed `0x005a5710` as the routed shout creator mirror, `0x005b4260` as the shout submit function, and no IDA function at `0x005b4220` or the exclusive end `0x005b4255`.
- [UID:0002SA][0x005b4220-0x005b4255.ShoutInputPaneRawConstructor](by-memory/0x005b4220-0x005b4255.ShoutInputPaneRawConstructor.md) remains a retained raw constructor body: session `80de0a67` reported zero raw-start xrefs and no whole-image pointer hit for `20 42 5B 00`, while `make_signature_for_range 0x005b4220-0x005b4255` produced a unique signature.
- Constructor evidence: prompt string `L"! "` at `0x00630a6c`, base constructor call `0x004f1c00`, primary vtable `0x0062fd00`, secondary vtable `0x0062fd50`, tertiary vtable `0x0062fd80`.
- Vtable evidence: primary slot `0x0062fd48 -> 0x005b4260`; creator helper `0x005a5710` allocates `0x108` bytes, calls the same `LineInputPane` base constructor with `L"! "`, and references the same prompt and vtable addresses.
- `OpenInputPaneForCurrentMode` calls `CreateShoutInputPane` when chat mode is `1`.
- Prompt/vtable xrefs are intentionally narrow: session `80de0a67` reported the `L"! "` prompt refs at only `0x005a575b` and `0x005b4227`, and the three Shout vtable pointer refs at only the creator mirror and raw constructor stores.
- Creator route evidence remains indirect for the raw body: `xref_query to 0x005a5710` returns callers `0x004812a2`, `0x005a5170`, and `0x005a63a7`, but the creator inlines the construction sequence instead of calling `0x005b4220`.
- 2026-06-26 B014 implementation for [UID:0001MF][0x005b4260-0x005b43bc.ShoutInputPane](by-memory/0x005b4260-0x005b43bc.ShoutInputPane.md) resolves the submit-child blank-C++ blocker. Current IDA MCP session `80de0a67` reconfirmed vtable-only xref `0x0062fd48 -> 0x005b4260`, no direct callers, `0x005b43bc-0x005b43c0` padding, state gate `g_pCollectionData+0x134102 == 2`, opcode `0x0e` subtype `1`, and send through `g_packetSender`.

## Reconstruction Notes

This class is reconstructable and attached to [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md). The raw constructor child [UID:0002SA][0x005b4220-0x005b4255.ShoutInputPaneRawConstructor](by-memory/0x005b4220-0x005b4255.ShoutInputPaneRawConstructor.md) is first-draft populated as `ShoutInputPane::ShoutInputPane() : LineInputPane(L"! ") {}`, and the exact submit child [UID:0001MF][0x005b4260-0x005b43bc.ShoutInputPane](by-memory/0x005b4260-0x005b43bc.ShoutInputPane.md) now emits first-draft `void ShoutInputPane::OnSubmitInput()` C++. Class-level C++ remains blank because executable bodies live on exact by-memory children; this page records the class shell and routes.

## Cross-References

- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- [UID:0002SA][0x005b4220-0x005b4255.ShoutInputPaneRawConstructor](by-memory/0x005b4220-0x005b4255.ShoutInputPaneRawConstructor.md)
- [UID:0003JS][0x00630a6c-0x00630a78.ShoutPromptString](by-memory/0x00630a6c-0x00630a78.ShoutPromptString.md)
- [UID:0001MF][0x005b4260-0x005b43bc.ShoutInputPane](by-memory/0x005b4260-0x005b43bc.ShoutInputPane.md)
- [UID:0001KO][0x005a4b60-0x005a5791.SayModeHelpers](by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md)
- [UID:0000C3][SayInputPane](by-class/SayInputPane.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `74`, confidence `76`.
- Evidence: the page documents chat purpose, file ownership, confirmed submit/factory helpers, opcode/subtype behavior, and constructor-boundary caveat; confidence remains capped because the projected constructor is not an IDA function.
- 2026-06-02 constructor split:
  - Before: the constructor was only listed as an IDA-missing projected start at `0x005b4220`.
  - After: raised to `82/84`, marked reconstructable, attached to [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md), and linked exact raw constructor [UID:0002SA][0x005b4220-0x005b4255.ShoutInputPaneRawConstructor](by-memory/0x005b4220-0x005b4255.ShoutInputPaneRawConstructor.md).
  - Evidence: IDA raw disassembly confirms the prompt string, base constructor call, vtable stores, creator xrefs, and submit vtable slot.
- 2026-06-12 A004 Batch 347 shout prompt child:
  - Before: `82/84`, below the strict direct-parent gate for the exact `L"! "` string child.
  - After: `85/86`, with [UID:0003JS][0x00630a6c-0x00630a78.ShoutPromptString](by-memory/0x00630a6c-0x00630a78.ShoutPromptString.md) documented as a class-owned source-declared literal child.
  - Evidence: live IDA MCP database `a002_batch346` reconfirmed the creator, raw constructor reference, submit function boundary, and exclusive `L"! "` prompt xrefs for this class.
- 2026-06-25 B001 source-quality implementation for [UID:0002SA][0x005b4220-0x005b4255.ShoutInputPaneRawConstructor](by-memory/0x005b4220-0x005b4255.ShoutInputPaneRawConstructor.md):
  - Before: the raw constructor child was documented as constructor-shaped but still carried a method-level blank-C++ blocker.
  - After: the child remains a raw/no-direct-route retained body but now emits first-draft constructor C++ as a `LineInputPane` base initializer with the `L"! "` prompt.
  - Evidence: current IDA MCP session `80de0a67` reconfirmed the exact raw range, no-function/no-xref/no-pointer-hit caveats, prompt and vtable refs, routed creator mirror callers, and unique signature; the submit method remains separate source-quality work.
- 2026-06-26 B014 source-quality implementation for [UID:0001MF][0x005b4260-0x005b43bc.ShoutInputPane](by-memory/0x005b4260-0x005b43bc.ShoutInputPane.md):
  - Before: the submit child remained blank under stale `95+` gate wording and this class page listed submit/helper/global naming as unresolved source-quality work.
  - After: the exact submit child emits first-draft `void ShoutInputPane::OnSubmitInput()` C++; class-level C++ stays blank because method bodies live on exact by-memory children.
  - Evidence: current IDA MCP session `80de0a67` reconfirmed the submit range, vtable-only slot `0x0062fd48`, no direct callers, tail padding, state gate, opcode/subtype packet shape, and `g_packetSender` send route.
