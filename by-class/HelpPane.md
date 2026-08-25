*** UID:000063 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "FontStyle.h"

class HelpPane : public Pane
{
public:
    class SimpleHelpTextPartPane : public Pane
    {
    public:
        SimpleHelpTextPartPane();
        virtual ~SimpleHelpTextPartPane() {}
        virtual void OnPaint();

    private:
        friend class HelpPane;

        void DrawStyledTextSegment(const FontStyleRule& style,
                                   int x,
                                   int y,
                                   const wchar_t *text,
                                   short charCount);

        SimpleUString m_text;
        FontStyle *m_fontStyle;
    };

    HelpPane(const wchar_t *text,
             Pane *owner,
             int x,
             int y,
             int horizontalAlign,
             int verticalAlign,
             const FontStyle *fontStyle);
    virtual ~HelpPane();

protected:
    virtual void OnPaintFrame();

private:
    void ApplyStyleState();

    unsigned int m_reserved;
    FontStyle m_fontStyle;
    unsigned int m_fillColor;
    unsigned int m_frameColor;
    SimpleHelpTextPartPane m_textPane;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# HelpPane

## UID00029O Status-Layer Consumer Evidence - 2026-07-21

HelpPane construction consumes independent `g_pStatusPaneLayer` through physical storage `0x0069b378`; this class does not own the global. The complete inherited/nested class surface, text-part layout and effects, resource/style/fade behavior, destructor, drawing, fields, vtable inventory, score, and formal block remain unchanged. This bounded synchronization adds no C++.

## Status

- Likely source file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- Address range: exact children [UID:0003ZY][0x004c6960-0x004c6dac.HelpPaneConstructor](by-memory/0x004c6960-0x004c6dac.HelpPaneConstructor.md), [UID:0003ZZ][0x004c6db0-0x004c6e49.HelpPaneDestructor](by-memory/0x004c6db0-0x004c6e49.HelpPaneDestructor.md), and [UID:000400][0x004c6e50-0x004c6ea9.HelpPaneOnPaintFrame](by-memory/0x004c6e50-0x004c6ea9.HelpPaneOnPaintFrame.md), with non-emitting parent split index [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md), raw style helper [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState](by-memory/0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState.md), and destructor thunks in [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- Current recovered file: `source-3/simroot_v2/class_HelpPane.cpp`
- Confidence: very strong for reusable tooltip behavior, exact core ranges, complete declaration/layout, retained ApplyStyleState source, nested ownership, and HelpPanes order; only stripped private lexical spellings and the historical semantic name of `m_reserved` remain capped.

## Class Purpose

`HelpPane` is the reusable styled tooltip pane. It measures multiline UTF-16 help text, computes a tooltip rectangle from parent scroll position and alignment parameters, clamps the rectangle to screen bounds, creates an embedded [UID:000064][HelpPane__SimpleHelpTextPartPane](by-class/HelpPane__SimpleHelpTextPartPane.md), and applies optional [UID:00005C][FontStyle](by-class/FontStyle.md)-compatible state such as foreground/background values and opacity.

## FontStyle Header Dependency

HelpPane requires the complete [UID:00005C][FontStyle](by-class/FontStyle.md) declaration before this class: it owns `FontStyle m_fontStyle` by value, accepts `const FontStyle *`, stores a borrowed `FontStyle *` in its nested pane, and passes `const FontStyleRule&` to styled drawing. Forward declarations alone cannot define the by-value member, so the formal CPP includes `FontStyle.h` before `class HelpPane`.

This is a dependency/placement repair, not an ownership transfer. HelpPane remains a constructor/GetRule consumer; FontStyle constructor/GetRule/Configure source stays in UID0000JI/UID00011T, and implicit vector destructor/growth bodies remain compiler-generated. Existing tooltip geometry, text, opacity, colors, nesting, and source order are unchanged.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `HelpPane` | [UID:0003ZY][0x004c6960-0x004c6dac.HelpPaneConstructor](by-memory/0x004c6960-0x004c6dac.HelpPaneConstructor.md) | Constructs the styled tooltip base, copies/initializes style state, creates the embedded text part, measures/clamps the tooltip rectangle, and propagates opacity/color state. |
| `~HelpPane` | [UID:0003ZZ][0x004c6db0-0x004c6e49.HelpPaneDestructor](by-memory/0x004c6db0-0x004c6e49.HelpPaneDestructor.md) | Ordinary destructor body; releases text/style storage, embedded text part, and base pane state. |
| `OnPaintFrame` | [UID:000400][0x004c6e50-0x004c6ea9.HelpPaneOnPaintFrame](by-memory/0x004c6e50-0x004c6ea9.HelpPaneOnPaintFrame.md) | Paints the tooltip background/frame region with configured colors. |
| retained private `ApplyStyleState` | [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState](by-memory/0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState.md) | Position-40 private source method, inlined into construction; applies base opacity, fill/frame paint colors, and embedded text-part opacity/mode state. No external/xref/vtable route is expected for this private helper. |
| `ScalarDeletingDestructor` | [UID:0003YW][0x004ce3f0-0x004ce42b.HelpPaneScalarDeletingDestructor](by-memory/0x004ce3f0-0x004ce42b.HelpPaneScalarDeletingDestructor.md) | Compiler scalar deleting destructor wrapper; formal C++ stays blank because source is ordinary `virtual HelpPane::~HelpPane()`. |

## Evidence Notes

- IDA decompilation shows `HelpPane::HelpPane` constructing a `Pane`, an embedded `HelpPane::SimpleHelpTextPartPane` at offset `0x124`, a `SimpleUString` help text, and a style/vector record.
- Live IDA MCP on 2026-06-14, session `a001_goal2_class_batch`, reconfirmed `sub_4C6960` size `0x44c`, `sub_4C6DB0` size `0x99`, `sub_4C6E50` size `0x59`, and `0x004c6eb0` as raw non-function code rather than an IDA-modeled function.
- `analyze_function 0x004c6960` confirms the constructor installs three `HelpPane` vtable pointers, constructs embedded `SimpleHelpTextPartPane` storage at `this + 0x124`, initializes text/style state, measures multiline UTF-16 help text, and is called by `SimpleHelpPane2` construction/factory paths at `0x004c74ff` and `0x004c7715`.
- `analyze_function 0x004c6e50` confirms the paint method uses the configured background and text colors at offsets `+0x11c` and `+0x120`, fills/draws through the GrafPort-style helpers, and has vtable/data xrefs from the HelpPane read-only-data cluster.
- The style/vector record is layout-compatible with [UID:00005C][FontStyle](by-class/FontStyle.md): enabled byte, two float fields, two scalar values, and a 16-byte-rule vector triplet.
- IDA shows `SimpleHelpPane2` and the adjacent [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md) at `0x004c7680` calling `HelpPane::HelpPane`.
- The generated `HelpPane` source matches the core placement, text measurement, screen clamp, and opacity behavior.
- [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState](by-memory/0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState.md) now records a 2026-06-19 source-quality pass: no external xrefs into the raw body, no function-pointer/vtable route, no local PE absolute pointer into the range, four calls to [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md), and touched offsets matching constructor-initialized style fields plus `OnPaintFrame` colors.
- 2026-06-20 supervisor Rule 26 split execution created exact child pages [UID:0003ZY][0x004c6960-0x004c6dac.HelpPaneConstructor](by-memory/0x004c6960-0x004c6dac.HelpPaneConstructor.md), [UID:0003ZZ][0x004c6db0-0x004c6e49.HelpPaneDestructor](by-memory/0x004c6db0-0x004c6e49.HelpPaneDestructor.md), and [UID:000400][0x004c6e50-0x004c6ea9.HelpPaneOnPaintFrame](by-memory/0x004c6e50-0x004c6ea9.HelpPaneOnPaintFrame.md); [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md) is now a non-emitting index over this class and [UID:000064][HelpPane__SimpleHelpTextPartPane](by-class/HelpPane__SimpleHelpTextPartPane.md).
- Parent attachment to [UID:0000JU][HelpPanes](by-file/HelpPanes.md) is now allowed: the class page is at the 80% completion gate, the parent file is over the gate, and the exact core/fade/helper pages all place the class in the HelpPanes source family.

## 2026-06-19 Style-State Field Notes

- [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState](by-memory/0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState.md) should be read as the parent `HelpPane` counterpart to the embedded text-part style-state helper, not as child-owned code.
- The copied style-enabled byte at `HelpPane +0xfc` gates the raw helper. Base opacity is stored at `HelpPane +0x100`: values `>= 1.0f` set base pane mode `1`; values in `0.0f <= opacity < 1.0f` set mode `3` and write inherited alpha/scalar storage at `HelpPane +0x90`; negative base opacity skips the base mode and alpha write but still reaches color and child handling.
- Within the copied parent `FontStyle` block, offset `+0x04` is the parent/base opacity and offset `+0x08` is the child text opacity consumed by the embedded text part.
- The style color source fields at `HelpPane +0x108/+0x10c` copy to `HelpPane +0x11c/+0x120`, the fill/frame paint fields used by `HelpPane::OnPaintFrame`.
- The embedded text child starts at `HelpPane +0x124`. Inside that child, `+0xf8` is owned `SimpleUString m_text`, `+0xfc` is borrowed `FontStyle *m_fontStyle`, `+0x8c` is inherited text alignment, and `+0x90` is inherited alpha. The parent stores the same borrowed style pointer alias at `HelpPane +0x220`; the raw helper reads child/text opacity at `[HelpPane +0x220] + 0x08`, sets child mode `1` for `textOpacity <= 0.0f`, and sets child mode `3` plus writes `HelpPane +0x1b4` for `0.0f < textOpacity <= 1.0f`.
- `HelpPane +0x1b4` is the embedded child's inherited alpha/scalar field at child `+0x90`. The parent alias at `+0x220` is intentionally not treated as an owned child field.
- The dependency formerly seen as generated `sub_5446B0` is [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md). The `1.0f` threshold formerly seen as `dword_6104B4` is [UID:0003AQ][0x006104ac-0x006104f0.SharedRdataFloatVectorConstants](by-memory/0x006104ac-0x006104f0.SharedRdataFloatVectorConstants.md), not a `HelpPanes` global.
- [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState](by-memory/0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState.md) now carries complete private source C++; its no-external-route evidence distinguishes private inlining from a callback or virtual route.

## 2026-06-17 Scalar Destructor Wrapper Split

- B003 split [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md) and assigned the exact `0x004ce3f0-0x004ce42b` wrapper to [UID:0003YW][0x004ce3f0-0x004ce42b.HelpPaneScalarDeletingDestructor](by-memory/0x004ce3f0-0x004ce42b.HelpPaneScalarDeletingDestructor.md) at `86/91`, owner/emitter [UID:000063].
- Source-facing name is `virtual HelpPane::~HelpPane()`. The wrapper and the `+0xa0/+0xa4` adjustor thunks are MSVC ABI output, not hand-authored source methods.
- The wrapper evidence reinforces the three-view vtable model: primary at `+0x00`, secondary/tertiary views at `+0xa0/+0xa4`, and `HelpPane` primary destructor slot data at `0x0061ab5c`.
- Related helper/field context from the split: `0x004c6db0` is `HelpPane::~HelpPane`, `0x00544580` is shared `Pane::~Pane` teardown, `HelpPane +0xfc` is `FontStyle m_fontStyle`, `+0x11c/+0x120` are `m_fillColor/m_frameColor`, and `+0x124` is embedded `m_textPane`.

## Ownership And Routing

The current `CANONICAL_OWNER` and `EMITTER_UIDS` values remain [UID:0000JU][HelpPanes](by-file/HelpPanes.md). Generated class coverage resolves this route to `auto-generated/NexusTK/ui/controls/HelpPanes.cpp` with no class dead end. The formal block now emits only a no-standalone class marker plus `[[CHILDREN]]`: [UID:0003ZY][0x004c6960-0x004c6dac.HelpPaneConstructor](by-memory/0x004c6960-0x004c6dac.HelpPaneConstructor.md), [UID:0003ZZ][0x004c6db0-0x004c6e49.HelpPaneDestructor](by-memory/0x004c6db0-0x004c6e49.HelpPaneDestructor.md), [UID:000400][0x004c6e50-0x004c6ea9.HelpPaneOnPaintFrame](by-memory/0x004c6e50-0x004c6ea9.HelpPaneOnPaintFrame.md), [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState](by-memory/0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState.md), and [UID:0003YW][0x004ce3f0-0x004ce42b.HelpPaneScalarDeletingDestructor](by-memory/0x004ce3f0-0x004ce42b.HelpPaneScalarDeletingDestructor.md) remain the exact child/support pages. Do not paste those method bodies into this class page. Constructor field names, the final style record declaration, the embedded text-part declaration, and the possible `HelpPane`/`ItemHelpPane` source split remain source-quality caveats rather than class-route blockers.

## Score Rationale

| Metric | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | Documents class purpose, constructor/destructor/paint/style-state method inventory, fresh constructor and paint IDA evidence, embedded text part, style/fade offsets, SimpleHelpPane2 factory callers, parent file route, and core/fade/destructor support pages. Still below final-code level because exact declaration layout and final original member spelling remain open. |
| Confidence | 89 | Strong from live IDA bounds/decompilation, HelpPanes parent evidence, read-only-data/vtable support, and exact memory pages. Capped below final audit because final source spelling and source split are still inferred. |

## Cross-References

- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md)
- [UID:0003ZY][0x004c6960-0x004c6dac.HelpPaneConstructor](by-memory/0x004c6960-0x004c6dac.HelpPaneConstructor.md)
- [UID:0003ZZ][0x004c6db0-0x004c6e49.HelpPaneDestructor](by-memory/0x004c6db0-0x004c6e49.HelpPaneDestructor.md)
- [UID:000400][0x004c6e50-0x004c6ea9.HelpPaneOnPaintFrame](by-memory/0x004c6e50-0x004c6ea9.HelpPaneOnPaintFrame.md)
- [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- [UID:0003YW][0x004ce3f0-0x004ce42b.HelpPaneScalarDeletingDestructor](by-memory/0x004ce3f0-0x004ce42b.HelpPaneScalarDeletingDestructor.md)
- [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState](by-memory/0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState.md)
- [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md)
- [UID:00005C][FontStyle](by-class/FontStyle.md)
- [UID:000064][HelpPane__SimpleHelpTextPartPane](by-class/HelpPane__SimpleHelpTextPartPane.md)
- [UID:0000D7][SimpleHelpPane2](by-class/SimpleHelpPane2.md)
- [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md)
- [UID:0003AQ][0x006104ac-0x006104f0.SharedRdataFloatVectorConstants](by-memory/0x006104ac-0x006104f0.SharedRdataFloatVectorConstants.md)

## Changes

- 2026-08-17 B006 accepted UID0000JI dependency callback:
  - Added `#include "FontStyle.h"` before the HelpPane declaration to satisfy by-value FontStyle and FontStyleRule uses.
  - Preserved the complete HelpPane/nested pane source, ownership, layout, method route, and metadata; this is solely the accepted shared-header dependency repair.

- 2026-06-20 supervisor Rule 26 HelpPaneCore split execution:
  - Added exact constructor/destructor/paint children [UID:0003ZY][0x004c6960-0x004c6dac.HelpPaneConstructor](by-memory/0x004c6960-0x004c6dac.HelpPaneConstructor.md), [UID:0003ZZ][0x004c6db0-0x004c6e49.HelpPaneDestructor](by-memory/0x004c6db0-0x004c6e49.HelpPaneDestructor.md), and [UID:000400][0x004c6e50-0x004c6ea9.HelpPaneOnPaintFrame](by-memory/0x004c6e50-0x004c6ea9.HelpPaneOnPaintFrame.md) to replace the old broad [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md) method-cluster routing.
  - Recorded that [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md) is now a non-emitting split index shared with [UID:000064][HelpPane__SimpleHelpTextPartPane](by-class/HelpPane__SimpleHelpTextPartPane.md), while this class keeps direct ownership of the `0x004c6960-0x004c6ea9` methods and [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState](by-memory/0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState.md).

- 2026-06-19 B012 style-state helper source-quality sync:
  - Updated [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState](by-memory/0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState.md) from historical `UpdateFadeState` wording to raw no-entry `HelpPane::ApplyStyleState()` / retained `HelpPaneFadeStateUpdate`.
  - Added class-level field notes for base opacity at `+0x100`, inherited base alpha at `+0x90`, fill/frame color copy `+0x108/+0x10c -> +0x11c/+0x120`, embedded child `+0x124`, borrowed parent `FontStyle *` alias `+0x220`, child text opacity `[+0x220]+0x08`, and child alpha at parent `+0x1b4` / child `+0x90`.
  - Preserved the no-entry/no-formal-C++ decision: no modeled function, no external xref, no function-pointer/vtable route, no local PE pointer into the range, and duplicated constructor-side style application logic.

- 2026-06-21 B013 embedded text-part sync:
  - Added the child-field mapping required by [UID:000064][HelpPane__SimpleHelpTextPartPane](by-class/HelpPane__SimpleHelpTextPartPane.md): child `+0xf8` owned `SimpleUString m_text`, child `+0xfc` borrowed `FontStyle *m_fontStyle`, child `+0x8c` inherited text alignment, and child `+0x90` inherited alpha.
  - Clarified the parent `FontStyle` opacity split: `FontStyle +0x04` controls parent/base opacity, while `FontStyle +0x08` controls embedded child text opacity through parent alias `HelpPane +0x220`.

- 2026-06-30 B004 HelpPanes empty-emitter first batch:
  - Added the accepted no-standalone class marker plus `[[CHILDREN]]` insertion point to the formal block.
  - Preserved [UID:0000JU][HelpPanes](by-file/HelpPanes.md) as owner/emitter and kept exact method/helper ownership on child pages instead of duplicating constructor/destructor/paint/style-state/destructor-wrapper bodies here.

- 2026-06-14 A003 Goal 2 low-score by-class refresh:
  - Raised completion/confidence from `80/88` to `85/89`.
  - Evidence: live IDA MCP reconfirmed constructor/destructor/paint sizes, raw non-function fade updater status, constructor vtable stores and embedded text-part construction at `this + 0x124`, SimpleHelpPane2/factory callers, and paint usage of configured background/text colors.
  - Routing: owner/emitter remains [UID:0000JU][HelpPanes](by-file/HelpPanes.md), generated through `auto-generated/NexusTK/ui/controls/HelpPanes.cpp`; final C++ remains blank pending source-quality field/declaration names and split decisions.
- 2026-06-17 B003 destructor-wrapper split sync:
  - Added exact scalar wrapper child [UID:0003YW][0x004ce3f0-0x004ce42b.HelpPaneScalarDeletingDestructor](by-memory/0x004ce3f0-0x004ce42b.HelpPaneScalarDeletingDestructor.md), preserved blank formal C++ policy, and recorded the vtable/field/helper context needed before any final destructor C++ pass.

- Completion/confidence score update: existed before as `0/0`; changed to `78/86`. Summary: tooltip purpose, constructor/destructor/paint methods, embedded text part, style compatibility, factory caller, and screen-clamp behavior are documented with strong confidence; remaining work is deeper field-level naming and final C++ reconstruction. Evidence: `HelpPaneCore`, `HelpTooltipDestructorThunks`, `SimpleHelpPane2Factory`, `FontStyle`, and embedded text-part cross-references.
- 2026-06-05: Marked reconstructable for generated output routing.
  - Before: `RECONSTRUCTABLE` was blank, leaving the reusable tooltip pane unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE`; left parent/emitter routing blank at that time because the class score was `78/86`, below the 80 completion attachment gate.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x004c6960`, `0x004c6db0`, `0x004c6e50`, and `0x004ce3f0`, plus constructor callers from the simple-help factory paths.
- 2026-06-06: Added fade-state helper and parent attachment.
  - Before: completion/confidence were `78/86`; the method list omitted the adjacent raw fade-state helper, and parent/emitter routing was blank because the page was below the completion gate.
  - After: completion/confidence are `80/88`, the current owner/emitter route is [UID:0000JU][HelpPanes](by-file/HelpPanes.md), and the method/evidence/cross-reference sections include [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState](by-memory/0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState.md).
  - Summary/evidence: the 2026-06-06 live IDA recheck for [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState](by-memory/0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState.md) confirmed the exact raw body, no external xrefs, four `PaneSetMode` calls, constructor-backed style fields, and paint-color state matching `HelpPane`.

## UID0003ZY Complete Source Closure - 2026-07-21

- Current metadata is `92/94`, owner/emitter [UID:0000JU][HelpPanes](by-file/HelpPanes.md), `RECONSTRUCTABLE:TRUE`, class position `5`. This declaration must precede existing SimpleHelpPane and SimpleHelpPane2 positions `10/20`.
- Exact object extent is `0x224`: inherited Pane occupies `0x000-0x0f7`; private `unsigned int m_reserved` preserves the untouched `+0xf8` word; `FontStyle m_fontStyle` is `+0xfc-0x11b`; `m_fillColor` and `m_frameColor` are `+0x11c/+0x120`; embedded `SimpleHelpTextPartPane m_textPane` starts at `+0x124` and occupies `0x100` bytes.
- The reserved word is not a recovered semantic field: constructor, destructor, paint, ApplyStyleState, nested, derived, and RTTI routes contain no access. It is left uninitialized and carries no raw offset comment in source.
- Public authored source is the seven-argument constructor [UID:0003ZY][0x004c6960-0x004c6dac.HelpPaneConstructor](by-memory/0x004c6960-0x004c6dac.HelpPaneConstructor.md), empty ordinary virtual destructor [UID:0003ZZ][0x004c6db0-0x004c6e49.HelpPaneDestructor](by-memory/0x004c6db0-0x004c6e49.HelpPaneDestructor.md), and nested constructor/destructor/OnPaint. Protected `OnPaintFrame` is [UID:000400][0x004c6e50-0x004c6ea9.HelpPaneOnPaintFrame](by-memory/0x004c6e50-0x004c6ea9.HelpPaneOnPaintFrame.md); private ApplyStyleState is UID00022N; nested private DrawStyledTextSegment is UID0003ZX.
- Nested `m_text` owns its SimpleUString storage; nested `m_fontStyle` borrows `&HelpPane::m_fontStyle` and is never destroyed. Parent and child ordinary destructors cause compiler cleanup; UID0003YW and UID0003Z0 remain non-emitting scalar deleting wrappers.
- Vtable heads `0x0061ab5c/0x0061aba8/0x0061abd8` and nested heads `0x0061aad4/0x0061ab20/0x0061ab50` prove Pane-only inheritance and the nested primary `+0x44` OnPaint slot. HelpPane has no direct Singleton base; SimpleHelpPane2 owns its later Singleton base.
- Historical class-level no-code, HelpPaneStyle, DrawText, fade-only, raw-helper-dead, and unknown-color conclusions remain above as dated provenance and are superseded by the complete managed declaration and exact child formals. Compiler vptr writes, cookie/EH cleanup, vector lowering, adjustor thunks, scalar wrappers, vtables, RTTI, and alignment remain excluded from authored C++.
