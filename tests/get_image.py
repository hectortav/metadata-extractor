if __name__ == '__main__':
    if __package__ is None:
        import sys
        sys.path.append('.')
        from metadata_extractor import metadata
    else:
        from ..metadata_extractor import metadata

    meta = metadata('https://interestingengineering.com/canada-is-banning-internal-combustion-engines-but-what-about-the-cold')
    print(meta["twitter:image"])