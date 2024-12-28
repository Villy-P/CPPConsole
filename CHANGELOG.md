# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## Upcoming

## 1.0.0 - 2024-12-27

### Added

#### ANSI Escape codes

- Added `isANSIEnabled` function
- Added `enableANSI` function

#### Colors

- Added `colorize` function, and its overloads
- Added `setColor` function, and its overloads

#### Console

- Added `print` function, and its overloads
- Added `println` function, and its overloads

#### Cursor

- Added `getCursorPosition` function
- Added `moveCursorHome` function
- Added `moveCursorToPosition` function
- Added `moveCursorUp` function
- Added `moveCursorDown` function
- Added `moveCursorRight` function
- Added `moveCursorLeft` function
- Added `moveCursorDownAndToStart` function
- Added `moveCursorUpAndToStart` function
- Added `moveCursorToColumn` function

#### Data

- Added `ConsoleCoord` structure

#### Dimensions

- Added `Dimensions` structure
- Added `getDimensions` function

#### Erase

- Added `ConsoleInfo` structure
- Added `getConsoleInfo` function
- Added `eraseFromCursorToEOS` function
- Added `eraseFromCursorToBOS` function
- Added `eraseEntireScreen` function
- Added `eraseFromCursorToEOL` function
- Added `eraseFromCursorToBOL` function
- Added `eraseCurrentLine` function

#### Graphics

- Added `Graphics` enum
- Added `bold` function
- Added `faint` function
- Added `italic` function
- Added `underline` function
- Added `blink` function
- Added `inverse` function
- Added `hidden` function
- Added `strikethrough` function
- Added `setBold` function
- Added `setFaint` function
- Added `setItalic` function
- Added `setUnderline` function
- Added `setBlink` function
- Added `setInverse` function
- Added `setHidden` function
- Added `setStrikethrough` function
- Added `set` function, and its overloads
- Added `clearGraphics` function

#### Print All

- Added `printAll` function, and its overloads
- Added `printlnAll` function, ands its overloads

#### Templates

- Added `iterable` template
- Added `is_map` template
- Added `is_not_string` template

#### Testing

- Added main testing function
